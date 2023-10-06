#include<linux/module.h>
#include<linux/kernel.h>

int init_module(void)
{
    printk(KERN_INFO "marvellous Infosystems : Initialization\n");
    return 0;
}

void cleanup_module(void)
{
    printk(KERN_INFO "marvellous Infosytems : Module removed\n");

}

MODULE_LICENSE("GPL");