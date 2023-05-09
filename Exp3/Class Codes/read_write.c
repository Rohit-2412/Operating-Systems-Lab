#include <stdio.h>
#include <unistd.h>

// how to display the data written using write() system call
// how to read the data using read() system call
int main()
{
    // write (file descriptor, message, size)
    // file descriptor: 0 = stdin, 1 = stdout, 2 = stderr
    int count;
    // write() returns the number of bytes written
    count = write(1, "System call session", 20);
    printf("\nThe data written is: %d\n\n", count);

    int r;
    char buf[50];
    // read (file descriptor, buffer, size)
    // return the number of bytes read
    r = read(0, buf, 50);
    write(1, buf, r);

    // if we pass any value other than 0, 1, 2, it will return -1
    return 0;
}