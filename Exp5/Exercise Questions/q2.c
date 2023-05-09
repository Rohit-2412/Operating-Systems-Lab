#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// wap using system calls for operation on process to create processes p1 -> p2 -> p3. also print the id and parent id of each process
int main()
{
    int pid;
    pid = getpid();

    // create p1
    pid = fork();
    if (pid == 0)
    {
        printf("Process created with pid: %d and parent id: %d\n", getpid(), getppid());
        // create p2
        pid = fork();
        if (pid == 0)
        {
            printf("Process created with pid: %d and parent id: %d\n", getpid(), getppid());
            // create p3
            pid = fork();
            if (pid == 0)
            {
                printf("Process created with pid: %d and parent id: %d\n", getpid(), getppid());
            }
        }
    }
    return 0;
}