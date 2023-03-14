#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xdb4c717, "module_layout" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x85bd1608, "__request_region" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x6b31d8af, "__register_chrdev" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x95fe0374, "module_put" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0x9f49dcc4, "__stack_chk_fail" },
	{ 0xcf2a6966, "up" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x1000e51, "schedule" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xdcb764ad, "memset" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x56470118, "__warn_printk" },
	{ 0xc5850110, "printk" },
	{ 0x36faa6d, "try_module_get" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C6EFDA124ADFCA8BA96A494");
