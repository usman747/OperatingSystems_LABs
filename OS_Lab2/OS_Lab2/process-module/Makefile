obj-m += process-module.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	-rmmod process-module
	dmesg -C
	insmod process-module.ko
	dmesg

