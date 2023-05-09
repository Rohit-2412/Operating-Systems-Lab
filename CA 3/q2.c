// wap to create heirarchy
/*
p1
/ \
p2 p3
*/
// verify relation using getppid() and getpid()
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t p1, p2, p3;
    p1 = fork();
    if (p1 == 0) // process p1
    {
        printf("P1 pid:%d parent pid:%d\n", getpid(), getppid());
        p2 = fork();
        if (p2 == 0) // child of p1 -> p2
        {
            printf("P2 pid:%d parent pid:%d\n", getpid(), getppid());
        }
        else // parent p1
        {
            p3 = fork();
            if (p3 == 0) // second child of p1 -> p3
            {
                printf("P3 pid:%d parent pid:%d\n", getpid(), getppid());
            }
        }
    }
    return 0;
}