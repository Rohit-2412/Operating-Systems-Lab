/*
   p1
 /   \
p2   p5
|     |
p3   p6
|     |
p4   p7

p4 = orphan
p7 = zombie process

p1 -> p2 -> p3 -> p4 -> p5 -> p6 -> p7
where p4 = orphan
      p7 = zombie process
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7;

    pid1 = fork();

    if (pid1 == 0) // child process of p1
    {
        printf("Process P1 created with pid: %d and parent id: %d\n", getpid(), getppid());

        pid2 = fork();

        if (pid2 == 0) // child process of p2
        {
            printf("Process P2 created with pid: %d and parent id: %d\n", getpid(), getppid());

            pid3 = fork();

            if (pid3 == 0) // child process of p3
            {
                printf("Process P3 created with pid: %d and parent id: %d\n", getpid(), getppid());

                pid4 = fork();

                if (pid4 == 0) // child process of p4
                {
                    // make p4 orphan
                    sleep(5);
                    printf("Process P4 created with pid: %d and parent id: %d\n", getpid(), getppid());
                }
                else // parent process of p4
                {
                    sleep(5);
                    pid6 = fork();

                    if (pid6 == 0) // child process of p6
                    {
                        printf("Process P6 created with pid: %d and parent id: %d\n", getpid(), getppid());

                        pid7 = fork();

                        if (pid7 == 0) // child process of p7
                        {
                            printf("Process P7 created with pid: %d and parent id: %d\n", getpid(), getppid());
                        }
                    }
                }
            }
        }
        else // parent process of p2
        {
            pid5 = fork();

            if (pid5 == 0) // child process of p5
            {
                printf("Process P5 created with pid: %d and parent id: %d\n", getpid(), getppid());
            }
        }
    }
    return 0;
}