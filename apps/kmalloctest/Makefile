
#compilation of a linux kernel module for our guest.

obj-m=kmalloctest.o

all:
	make -C /home/nicko/implementations/x86/buildroot/output/build/linux-5.15 M=$(PWD) modules
clean:
	rm modules.order Module.symvers  kmalloctest.ko kmalloctest.mod* kmalloctest.o
