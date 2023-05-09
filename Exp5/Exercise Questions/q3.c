#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*
   p1
 /   \
p2   p4
|     |
p3   p5

p4 = orphan
p5 = zombie process
*/
int main()
{
    pid_t pid1, pid2, pid3, pid4, pid5;
    pid1 = getpid();

    // display p1 name and id and parent id
    printf("Process P1 created with pid: %d and parent id: %d\n", getpid(), getppid());

    // create p2
    pid2 = fork();
    if (pid2 == 0) // child process
    {
        // display p2 name and id and parent id
        printf("Process P2 created with pid: %d and parent id: %d\n", getpid(), getppid());

        // create p3
        pid3 = fork();
        if (pid3 == 0)
        {
            // display p3 name and id and parent id
            printf("Process P3 created with pid: %d and parent id: %d\n", getpid(), getppid());
        }
    }
    else // parent process
    {
        // create p4 process and make it orphan
        pid4 = fork();
        if (pid4 == 0)
        {
            // sleep p4 for 2 seconds
            sleep(5);

            // display p4 name and id and parent id
            printf("Process P4 created with pid: %d and parent id: %d\n", getpid(), getppid());

            // create p5 process and make it zombie
            pid5 = fork();
            if (pid5 == 0)
            {
                // display p5 name and id and parent id
                printf("Process P5 created with pid: %d and parent id: %d\n", getpid(), getppid());
            }
            else
            {
                // make p5 zombie
                sleep(2);
                printf("Process P5 is zombie now\n");
            }
        }
    }
    return 0;
}
