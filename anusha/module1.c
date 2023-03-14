#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
//static int hello_module(void)
int init_module(void)
{
	pr_info("My basic module is\n");
	pr_info("Loaded successully\n");
	return 0;
}

//static void hello_exit_module(void)

void cleanup_module(void)
{
	printk(KERN_INFO "Mybasic module\n");
       printk(KERN_INFO "offloaded successfully\n");
}

MODULE_AUTHOR("ANUSHA");
MODULE_LICENSE("GPL_V2");
MODULE_DESCRIPTION("Basic module\n");
