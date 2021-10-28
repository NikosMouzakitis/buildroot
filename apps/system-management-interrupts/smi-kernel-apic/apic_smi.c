#include <linux/module.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/hardirq.h>
#include <linux/preempt.h>
#include <linux/sched.h>
#include <linux/io.h>
#include <asm/apic.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("N.Mouzakitis");

static int __init my_start(void)
{
	printk(KERN_INFO "Module Loaded\n");
	unsigned long flags;

	preempt_disable();
	raw_local_irq_save(flags);

	//sending the SMI throught the APIC.
	apic->icr_write(0x00000200,0x00000000);

	raw_local_irq_restore(flags);
	preempt_enable();

	printk(KERN_INFO "SMI via icr_write() send.\n");
	
	return 0;
}

static void __exit my_exit(void)
{
	printk(KERN_INFO "Unloading module\n");
}

module_init(my_start);
module_exit(my_exit);
