obj-m = driver_blocking_calls.o
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	rm -f *.ko *.mod.c *.o basic_driver.mod.cmd basic_driver.mod.o.cmd basic_driver.o.cmd basic_driver.ko.cmd modules.order
