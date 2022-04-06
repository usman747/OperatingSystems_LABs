#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>

#define M_AUTHOR "Brian Setz <brian.setz@iaas.uni-stuttgart.de>" 
#define M_DESC "Process Module" 

void list_processes(struct task_struct *task) // task_struct is defined in <linux/sched.h>
{
  for_each_process(task) { // for_each_process is a helper method defined in <linux/sched.h>
    
    // TODO Implement: for each task print the executable name, PID, and TGID 
    printk("excutable name = %s, PID = %d, TGID = %d\n", task->comm, task->pid, task->tgid);
  }
}

int init(void)
{
  printk(KERN_INFO "pm: init(void)\n");

  printk(KERN_INFO "pm: Module author = %s\n", M_AUTHOR);
  printk(KERN_INFO "pm: Module description = %s\n", M_DESC);

  list_processes(&init_task);

  return 0;
}

void exit(void)
{
  printk(KERN_INFO "pm: exit(void)\n");
}

module_init(init); // Define module entry point
module_exit(exit); // Define module exit point

MODULE_LICENSE("GPL");
MODULE_AUTHOR(M_AUTHOR);
MODULE_DESCRIPTION(M_DESC);
