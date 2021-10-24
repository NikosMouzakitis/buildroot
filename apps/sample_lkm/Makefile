
#compilation of a linux kernel module for our guest.

obj-m=mymodule.o

all:
	make -C /home/nicko/implementations/buildroot/output/build/linux-5.10.7 M=$(PWD) modules
clean:
	rm modules.order Module.symvers mymodule.ko mymodule.mod* mymodule.o

