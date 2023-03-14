//wap to perform the wait event calls on the below driver code 

#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/poll.h>
#include<linux/ioport.h>
#include<linux/errno.h>
#include<linux/cdev.h>
#include<linux/wait.h>
#define SIZE 5

static int mydev_init(void);
static void mydev_release(void);

MODULE_AUTHOR("ANUSHA");
MODULE_LICENSE("GPL");

//***********************************************Driver routine declarations****************************************************

static int mychar_open(struct inode *inode,struct file *file);
static int mychar_close(struct inode *inode,struct file *file);
static ssize_t mychar_write(struct file *file,const char *buff,size_t len,loff_t *offset);
static ssize_t mychar_read(struct file *file,char *buff,size_t len,loff_t *offset);

wait_queue_head_t wwq;
DECLARE_WAIT_QUEUE_HEAD(wwq);
wait_queue_head_t rwq;
DECLARE_WAIT_QUEUE_HEAD(rwq);

size_t n=0;

//.........................Device context info (or) per device context info (or)driver context info..............................

struct d_context
{
	char buf[1024];
	int no_char;
	int base_address;//hardware resources
	int IRQ_lineno;//hardware resources
	struct cdev c_dev;
}my_context;

//********************************File operation structure**********************************************************************
//........................Storing the base address of driver routines in function pointers of structure...........................

static struct file_operations my_routines=
{
	.read=mychar_read,
	.open=mychar_open,
	.write=mychar_write,
	.release=mychar_close,
};

//********************************************Character driver initialization*****************************************************

static int mydev_init(void)
{
	int res=0;
	dev_t devno=0;//dev_t is the typedef of int in kernel
	devno=MKDEV(42,0);//MKDEV is a predefinef macro which associates with major and minor number
	res=register_chrdev_region(devno,1,"Anusha_char");//1st arg=major and minor no, 2nd arg=no.of devices,3rd arg=driver name
	if(res<0)
	{
		printk("<1>""Anusha_char is not loaded successfully\n");//-1 fail condition
		return res;
	}
	else
	{
		printk("<1>""Anusha_char is successfully loaded\n");//0:successful condition
	}
	cdev_init(&my_context.c_dev,&my_routines);//linking cdev_ogject and file operations
	//1st arg=base address of cdev_object,2nd arg=file operation base address
	
	my_context.c_dev.owner=THIS_MODULE;//THIS_MODULE predefined macro...it will return the basic address of the driver

	res=cdev_add(&my_context.c_dev,devno,1);//after linking loading into kernel space
	//1st arg=base address of cdev_object,2nd arg=device no(major and minor no),3rd arg=no.of devices (currently only one)
	
	if(res<0)
	{
		printk("<1>""cdev_object is not loaded successfully\n");//-1:fail condition
		unregister_chrdev_region(devno,1);//unregistering the Anusha_char from kernel
	}
	
	printk("<1>""cdev_object added successfully\n");//0:successfully loaded
	my_context.no_char=0;
	return res;
}

/***************************Character driver exit function****************************************/

static void mydev_release(void)
{
	dev_t devno=MKDEV(42,0); //MKDEV is a predefined macro with associates with major and minor number
	cdev_del(&my_context.c_dev);//Deleting cdev_object
	unregister_chrdev_region(devno,1);//unregistering Anusha_char from kernel
	printk("<1>""Anusha_char is unloaded successfully\n");
}

/*************************************************************************************************/

//Load device file dynamically or statically into kernel space ....(#mknod /my/dev c 42 0)
//i_rdev=devno,*i_cdev=&mycontext.c_dev are the members of inode object of "/dev/mydev" are stored automatically when a request comes from application (open()) system call

static int mychar_open(struct inode *inode,struct file *file)//1st arg=inode object base address,2nd arg=base address of file object of "/dev/mydev"
{
	try_module_get(THIS_MODULE);//It will increase the count of no.of devices communicating to driver
	file->private_data=&my_context;//storing the base address of device context info in file_object private data
	if(file->f_mode & FMODE_READ)//FMODE_READ is a predefined macro ,it has a unique identifier for read_mode
		printk("<1>""open for read mode\n");
	if(file->f_mode & FMODE_WRITE)//FMODE_WRITE is a predefined macro,it has a unique identifier for write_node
		printk("<1>""open for write mode\n");
	return 0;//returning zero for successful open

}

/*****************************************Driver routine close************************************/
static int mychar_close(struct inode *inode,struct file *file)
{
	module_put(THIS_MODULE);//It will decrease the count of no.of devices communicating to driver
	printk("<1>""device file is closed\n");
	return 0;//returning zero for successful close
}

/********************************************Driver routine write*********************************/
static ssize_t mychar_write(struct file *file,const char *buff,size_t len,loff_t *offset)
{
	struct d_context *tdev;
	wait_event_interruptible(wwq,n<SIZE);
	tdev=file->private_data;//storing the address of device context info of particular device file into a device context pointer
	size_t a;
	a=SIZE-n;
	if(len>a)
		len=a;
	copy_from_user(tdev->buf,buff,len);
	n=n+len;
	tdev->no_char=len;
	printk("<1>""write is called\n");
	printk("<1>""data received from app %s-%d(no_of char)\n",tdev->buf,tdev->no_char);
	wake_up_interruptible(&rwq);
	return (size_t)len;
}
/*********************************Driver routine read********************************/

static ssize_t mychar_read(struct file *file,char *buff,size_t len,loff_t *offset)
{
	struct d_context *tdev;
	wait_event_interruptible(rwq,n>0);
	tdev=file->private_data;//storing the address of device context info of particular device file into a device context pointer
	size_t uc;
	if(n<len)
		uc=n;
	else
		uc=len;
	copy_to_user(buff,tdev->buf,uc);//copying the data to user read code
	n=n-uc;
	tdev->no_char=uc;
	printk("<1>""read is called\n");
	printk("<1>""data sent to app %s-%s-%d(no of char)\n",tdev->buf,buff,tdev->no_char);
	wake_up_interruptible(&wwq);
	return (size_t)uc;
}
/********************************************************************************************/

module_init(mydev_init);//module_init is predefined macro which hold the address of driver initialization routine
module_exit(mydev_release);//module_exit is predefined macro which hold the address of driver exit routine
 





