CONFIG_MODULE_SIG=n
KBUILD_CFLAGS   +=  -g -Wall
EXTRA_CFLAGS    +=  -I$(PWD)/

obj-m += driver-3.o



all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
