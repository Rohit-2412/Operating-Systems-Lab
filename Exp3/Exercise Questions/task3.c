#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/*
Question: Write a program using system calls to read the contents of a file without using char array and display the contents on the console.(Do not use any built in function like sizeof() and strlen())
*/
int main()
{
    // declare the file descriptors
    int file_to_read;

    // open the file to read
    file_to_read = open("exp3t3.txt", O_RDONLY, 0777);

    // read the data from the file
    char c;

    // read the data from the file character by character and count the number of characters
    while (read(file_to_read, &c, 1) != 0)
    {
        write(1, &c, 1);
    }

    // close the file
    close(file_to_read);
    return 0;
}
