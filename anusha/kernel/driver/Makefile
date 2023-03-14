obj-m:= basic_driver.o
all:
	make ARCH=arm64 CROSS_COMPILE=/home/engineer/Downloads/buildroot-2022.02.9/output/host/bin/aarch64-linux- -C /home/engineer/Downloads/buildroot-2022.02.9/output/build/linux-custom M=$(shell pwd) modules
	#make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

clean:
	rm -f *.ko *.mod.c *.o basic_driver.mod.cmd basic_driver.mod.o.cmd basic_driver.o.cmd basic_driver.ko.cmd modules.order

	# make ARCH=arm64 CROSS_COMPILE=/home/engineer/Downloads/buildroot-2022.02.9/output/host/bin/aarch64-linux- -C /home/engineer/Downloads/buildroot-2022.02.9/output/build/linux-custom M=$(shell pwd) modules

