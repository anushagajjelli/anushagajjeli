#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x4775f460, "module_put" },
	{ 0x92997ed8, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xc0314d3d, "try_module_get" },
	{ 0x3eeb2322, "__wake_up" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xe2c17b5d, "__SCT__might_resched" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0x8c26d495, "prepare_to_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0x92540fbf, "finish_wait" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xd0da656b, "__stack_chk_fail" },
	{ 0x6bd0e573, "down_interruptible" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xcf2a6966, "up" },
	{ 0x87ada05a, "__register_chrdev" },
	{ 0xdbdf6c92, "ioport_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x84bd3073, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C6EFDA124ADFCA8BA96A494");
