#include <sys/syscall.h>
#include <stdio.h>

int main()
{
    unsigned long res[100];
    long sysvalue = syscall(333, 721, res);
    printf("%ld %ld", res[0], sysvalue);
    return 0;
}