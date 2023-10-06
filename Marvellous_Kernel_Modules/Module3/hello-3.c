#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */


//we can create local and global variable
//to access to evryone __ is used
//global static beacuse it can not access by anyone outside this file
//static varible called as load time varible , whenwevr exe file get loaded memory for static varible get allocated.
//you can create any type of datatype
static int hello3_data __initdata = 21;  //parameter pass karnya sathi //special variable

static int __init hello_3_init(void)    //special variable __init ,__exit 
{
	printk(KERN_INFO "Marvellous : module inserted with data %d\n", hello3_data);
	return 0;
}

static void __exit hello_3_exit(void)
{
	printk(KERN_INFO "Marvellous : module removed\n");
}

module_init(hello_3_init);
module_exit(hello_3_exit);
MODULE_LICENSE("GPL");
