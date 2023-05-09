#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
/*
copy the numbers from a file to another file
*/
int main()
{
    int fd1, fd2, n;
    char buf[100];
    fd1 = open("a.txt", O_RDONLY);

    fd2 = open("b.txt", O_WRONLY | O_CREAT, 0777);

    char temp;
    while (read(fd1, &temp, 1) != 0)
    {
        if (temp >= '0' && temp <= '9')
        {
            write(fd2, &temp, 1);
        }
    }

    close(fd1);
    close(fd2);
    return 0;
}