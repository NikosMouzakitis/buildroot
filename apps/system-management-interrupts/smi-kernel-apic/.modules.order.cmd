cmd_/home/nicko/implementations/buildroot/apps/system-management-interrupts/smi-kernel-apic/modules.order := {   echo /home/nicko/implementations/buildroot/apps/system-management-interrupts/smi-kernel-apic/apic_smi.ko; :; } | awk '!x[$$0]++' - > /home/nicko/implementations/buildroot/apps/system-management-interrupts/smi-kernel-apic/modules.order
