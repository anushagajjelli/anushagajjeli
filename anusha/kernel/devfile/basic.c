

#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/err.h>
#include<linux/module.h>
#include<linux/kdev_t.h>

dev_t devno;
static struct class *class;
static struct device *dev;
static struct cdev cdev_obj;
static struct file_operations file={ 
	.owner=THIS_MODULE};


static int __init my_init(void)
{
	int ret;
	
	ret=alloc_chrdev_region(&devno,0,1,"Anusha");
	if(ret<0)
	{
		printk("Failed to register with kernel\n");
		return -1;
	}
	printk("Major no:%d  Minor no:%d\n",MAJOR(devno),MINOR(devno));

	cdev_init(&cdev_obj,&file);

	cdev_add(&cdev_obj,devno,1);
	
	class=class_create(THIS_MODULE,"my_class");
	if(class==NULL)
	{
		printk("Failed to create the class\n");
		cdev_del(&cdev_obj);//if class not created we have to delete the loaded cdev objects and unregister kernel and driver
		unregister_chrdev_region(devno,1);
		return -1;
	}

	dev=device_create(class,NULL,devno,NULL,"my_device");
	if(dev==NULL)
	{
		pr_info("Faileed to create the device file\n");
		return -1;
	}
	return 0;

}


static void __exit my_exit(void)
{
	device_destroy(class,devno);
	class_destroy(class);
	unregister_chrdev_region(devno,1);
	pr_info("Kernel module removed sucessfully\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("BHARGAVI");






