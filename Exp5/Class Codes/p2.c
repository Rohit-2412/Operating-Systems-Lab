#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid;
    pid = getpid();

    printf("Current process id: %d\n", pid);
    printf("forking a child process\n");
    pid = fork();
    if (pid == 0)
    {
        printf("child process is sleeping\n");
        sleep(10);
        printf("orphan child parent %d\n", getppid());
    }
    else
    {
        printf("parent process completed\n");
    }

    return 0;
}