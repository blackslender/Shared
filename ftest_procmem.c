#include <stdio.h>
#include <unistd.h>
#include <procmem.h>
#include <sys/types.h>
#include <stdint.h>

int main()
{
    pid_t pid = getpid();
    printf("PID:\t\t%d\n", pid);
    struct proc_segs info;
    if (procmem(pid, &info) == 0)
    {
        printf("Student ID:\t\t%lu\n", info.mssv);
        printf("Code segment: \t%lx-%lx\n", info.start_code, info.end_code);
        printf("Data segment: \t%lx-%lx\n", info.start_data, info.end_data);
        printf("Heap segment: \t%lx-%lx\n", info.start_data, info.end_data);
        printf("Start stack: \t%lx\n", info.start_stack);
    }
    else
        printf("Syscall fail, cannot get information of process\n");
    return 0;
}