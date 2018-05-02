#include <linux/module.h> // Needed by all modules
#include <linux/kernel.h> // KERN_INFO
#include <linux/sched/signal.h>
#include <linux/sched.h> // for_each_process, pr_info
struct proc_segs
{
    unsigned long mssv;
    unsigned long start_code;
    unsigned long end_code;
    unsigned long start_data;
    unsigned long end_data;
    unsigned long start_heap;
    unsigned long end_heap;
    unsigned long start_stack;
    unsigned long end_stack;
};
static int pid = 0;
int init_module(void)
{
    printk("---------------------------\n");
    struct task_struct *task;
    for_each_process(task) if (task->pid == pid)
    {
        printk("My student ID: 1614063\n");
        printk("Start code: \t0x%lx\n", task->mm->start_code);
        printk("End code: \t0x%lx\n", task->mm->end_code);
        printk("Start data: \t0x%lx\n", task->mm->start_data);
        printk("End data: \t0x%lx\n", task->mm->end_data);
        printk("Start heap: \t0x%lx\n", task->mm->start_brk);
        printk("End heap: \t0x%lx\n", task->mm->brk);
        printk("Start stack: \t0x%lx\n", task->mm->start_stack);
    }
    return 0;
}

void cleanup_module(void)
{
}
module_param(pid, int, 0);
MODULE_LICENSE("Hoangvan - 1614063");