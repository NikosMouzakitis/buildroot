#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");
struct mytype {
	char a[200];
	int b[30];
};

struct mytype *p;
int allocation_flag;

static int hello_init(void)
{
	pr_info("newmod: inserted\n");
	pr_info("size of test struct is : %d bytes\n",sizeof(struct mytype));

	allocation_flag = 0;

	p = kmalloc(sizeof(struct mytype), GFP_KERNEL);
	if(!p) {
		pr_info("Allocation failed..\n");
	} else {
		pr_info("Allocation success..\n");
		allocation_flag = 1;
	}


	return 0;
}

static void hello_exit(void)
{
	pr_info("newmod: removed\n");

	if(allocation_flag) {
		kfree(p);
		pr_info("newmod: free allocated mem success.\n");
	}
}

module_init(hello_init);
module_exit(hello_exit);
