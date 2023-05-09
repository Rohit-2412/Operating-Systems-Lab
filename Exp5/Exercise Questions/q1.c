#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
// header file for fork() and getpid()

int main()
{
    int n = 3; // number of fork calls to simulate
    pid_t pid;

    // fork n times
    for (int i = 0; i < n; i++)
    {
        pid = fork();

        // if fork() returns 0, this is the child process
        if (pid == 0)
        {
            printf("Child process %d, parent process %d\n", getpid(), getppid());
            break; // exit loop to prevent child from forking more processes
        }
    }

    // if pid > 0, this is the parent process
    if (pid > 0)
    {
        printf("Parent process %d\n", getpid());
    }
    return 0;
}