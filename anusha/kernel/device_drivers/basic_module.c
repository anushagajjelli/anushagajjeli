#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

//static int hello_module(void)
int init_module(void)
{
	pr_info("My first code:");
	pr_info("loaded successfully\n");
	return 0;
}

//static int hello_exit(void)

void cleanup_module(void)
{
	printk(KERN_INFO "Driver is loaded\n");
	printk(KERN_INFO "offloaded successfully\n");
}

MODULE_AUTHOR("ANUSHA");
MODULE_LICENSE("GPL_V2");
MODULE_DESCRIPTION("BASIC DRIVER MODULE\n");
