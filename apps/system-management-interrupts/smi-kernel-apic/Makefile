
#compilation of a linux kernel module for our guest.

obj-m=apic_smi.o

all:
	make -C /home/nicko/implementations/buildroot/output/build/linux-5.10.7 M=$(PWD) modules
clean:
	rm modules.order Module.symvers apic_smi.ko apic_smi.mod* apic_smi.o

