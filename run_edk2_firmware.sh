#!/bin/bash

cp /home/nicko/BUSYBOX_INSTALLATION/edk2/Build/OvmfX64/DEBUG_GCC48/FV/OVMF* ovmf-edk2/

machine="q35,smm=on"\

#run the virtual machine,with SMM enabled using the firmware created by the EDK2 codebase.
qemu-system-x86_64 \
	-M $machine --enable-kvm  -m 4096 \
	-smp 2 \
	-bios ovmf-edk2/OVMF.fd \
	-drive file=output/images/rootfs.ext2,if=virtio,format=raw \
	-kernel output/images/bzImage \
	-append "rootwait root=/dev/vda console=tty1 console=ttyS0" \
	-global driver=cfi.pflash01,property=secure,value=on \
	-drive if=pflash,format=raw,unit=0,file=ovmf-edk2/OVMF_CODE.fd,readonly=on \
	-drive if=pflash,format=raw,unit=1,file=ovmf-edk2/OVMF_VARS.fd \
	-global ICH9-LPC.disable_s3=1 \
	-nic user,model=virtio,hostfwd=tcp::22222-:22 \
	-chardev stdio,id=deb \
	-device isa-debugcon,iobase=0x402,chardev=deb \

