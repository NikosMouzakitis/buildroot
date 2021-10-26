#!/bin/sh

qemu-system-x86_64 -M pc \
		-smp 2 \
		--enable-kvm \
		-kernel output/images/bzImage \
		-drive file=output/images/rootfs.ext2,if=virtio,format=raw \
		-append "rootwait root=/dev/vda console=tty1 console=ttyS0" \
		-nographic \
		-nic user,model=virtio,hostfwd=tcp::22222-:22 \

#		-netdev id=net0,type=user -nic user,hostfwd=tcp::22222-:22 \
#		-device virtio-net-pci,netdev=net0,romfile= \

					      
#-netdev id=net0,type=user,hostfwd=tcp::22222-:22 \
#-nic user,hostfwd=tcp::22222-:22 -net user -redir tcp:22222::22 \

# -net nic,model=virtio -net user \
