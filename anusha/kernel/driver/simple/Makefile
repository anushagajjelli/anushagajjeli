obj-m += simpserial.o

all:
	make ARCH=arm64 CROSS_COMPILE=/home/engineer/Downloads/buildroot-2022.02.9/output/host/bin/aarch64-linux- -C /home/engineer/Downloads/buildroot-2022.02.9/output/build/linux-custom M=$(shell pwd) modules
	#make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
	#gcc -o devread devread.c
	#gcc -o devwrite devwrite.c
	#gcc -o devtest devtest.c

clean:
	rm -f *.o *.ko *.mod.c
	rm -f devread devwrite devtest
