#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define nl printf("\n")

/*
Question: Write a program using system calls to read from console until user enters $ and write the data to a file.
*/
int main()
{
    // declare the file descriptors
    int file_to_write;

    // open the file to write
    file_to_write = open("exp3t2.txt", O_WRONLY | O_CREAT, 0777);

    // read the data from the console
    char c;

    // read the data from the console character by character
    while (read(0, &c, 1) != 0)
    {
        // check if the character is $
        if (c == '$')
        {
            // break the loop
            break;
        }
        // write the character to the file
        write(file_to_write, &c, 1);
    }

    // close the file
    close(file_to_write);

    return 0;
}
