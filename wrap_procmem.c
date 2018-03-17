#include "wrap_procmem.h"
#include <linux/kernel.h>
#include <sys/syscall.h>

long procmem(pid_t pid, struct proc_segs *info)
{
    return syscall(333, pid, info);
}