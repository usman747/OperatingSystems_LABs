obj-m += hello-module.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	-rmmod hello-module
	dmesg -C
	insmod hello-module.ko
	dmesg

