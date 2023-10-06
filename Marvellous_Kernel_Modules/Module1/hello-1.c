// This header file is required by all kernel modules
#include <linux/module.h>                 //init module ani cleanup module

// This header file is required for KERN_INFO
#include <linux/kernel.h>  //linux kernel che swatche macro ani function che prototye ya madhe

// This function gets called automattically when module gets loaded by insmod

// This function returns 0 if it successfully executed otherwise it returns non zero value

int init_module(void)  //in (void) means function not take any parameter
{
	printk(KERN_INFO "Marvellous Infosystems : Initialisation\n");  //KERN_INFO means mala kernel chya ddairy madhe info liha
                                                                    //printk is special version of print function to write
    return 0;
}

// This function gets called automatically when module gets removed from memory by rmmod
void cleanup_module(void)
{
	printk(KERN_INFO "Marvellous Infosystems : Module removed\n");
}

MODULE_LICENSE("GPL");
// All the information which is printed by printk function is available in /var/log/syslog file.


//kernel cha scource code active ahe karan os chalu ahe , kernel chya text section madhe jaga aste tith kernel module load hoto
//kernel module , kernel chya text region madhe jato.



//in MakeFile - command in all: is used to run makefile of kernel which is in lib/modules6./build/makefile
//in kernel makefile to build the kernel module , from .c to .ko (procedure kashi asavi ye yaat lihal ahe)
//hi makefile kernel chi sagali kade run honyasathi path madhe $(shell uname -r) 
//files kuth padu tayar zalelya, tar ithch pad (pwd)(ya folder var drop karnar)

//insmod called internally init_module 
//rmmod internally calls cleanup_moddule 


