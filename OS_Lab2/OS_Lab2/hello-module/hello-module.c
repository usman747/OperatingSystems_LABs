#include <linux/module.h>

#define M_AUTHOR "Brian Setz <brian.setz@iaas.uni-stuttgart.de>" 
#define M_DESC "Hello Module" 

int init(void)
{
  printk(KERN_INFO "hm: init(void)\n"); // printk is a special kernel version of printf

  return 0;
}

void exit(void)
{
  printk(KERN_INFO "hm: exit(void)\n");
}

module_init(init); // Define module entry point
module_exit(exit); // Define module exit point

// Module info
MODULE_LICENSE("GPL");
MODULE_AUTHOR(M_AUTHOR);
MODULE_DESCRIPTION(M_DESC);
