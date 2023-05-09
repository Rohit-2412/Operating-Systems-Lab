#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define nl printf("\n")

/*
Question: Write a program using system calls to copy half the contents of the file to a newly created file.
a) first half
b) second half
*/
int main()
{

    // declare the file descriptors
    int file_to_read, file_to_write;

    // open the file to read
    file_to_read = open("original.txt", O_RDONLY, 0777);

    // open the first file to write
    file_to_write = open("first.txt", O_WRONLY | O_CREAT, 0777);

    // declare a buffer to store the data
    char buffer[500];

    // read the data from the file
    // read() will return the number of bytes read
    int bytes_read = read(file_to_read, &buffer, 50);

    // write the data to the first file
    // write(file descriptor, buffer {source of data}, size to write)
    write(file_to_write, buffer, bytes_read / 2);

    // close the first file
    close(file_to_write);

    // open the second file to write
    file_to_write = open("second.txt", O_WRONLY | O_CREAT, 0777);

    // write the data to the second file
    write(file_to_write, buffer + bytes_read / 2, bytes_read / 2);

    // close the second file
    close(file_to_write);

    // close the file to read
    close(file_to_read);

    return 0;
}

// // approach 2
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <fcntl.h>
// #define nl printf("\n")

// /*
// Question: Write a program using system calls to copy half the contents of the file to a newly created file.
// a) first half
// b) second half
// */
// int main()
// {

//     // declare the file descriptors
//     int file_to_read, file_to_write;

//     // open the file to read
//     file_to_read = open("original.txt", O_RDONLY, 0777);

//     // open the first file to write
//     file_to_write = open("first.txt", O_WRONLY | O_CREAT, 0777);

//     int size_of_file = 0;
//     char c;
//     // read the data from the file character by character
//     // read() will return the number of bytes read
//     while (read(file_to_read, &c, 1) != 0)
//     {
//         size_of_file++;
//     }

//     // close the file to read
//     close(file_to_read);

//     // open the file to read
//     file_to_read = open("original.txt", O_RDONLY, 0777);

//     // open first file to write
//     file_to_write = open("first.txt", O_WRONLY | O_CREAT, 0777);

//     // write first half of the file to the first file
//     for (int i = 0; i < size_of_file / 2; i++)
//     {
//         read(file_to_read, &c, 1);
//         write(file_to_write, &c, 1);
//     }

//     // close the first file
//     close(file_to_write);

//     // open the second file to write
//     file_to_write = open("second.txt", O_WRONLY | O_CREAT, 0777);

//     // write the second half of the file to the second file
//     for (int i = 0; i < size_of_file / 2; i++)
//     {
//         read(file_to_read, &c, 1);
//         write(file_to_write, &c, 1);
//     }

//     // close the second file
//     close(file_to_write);

//     return 0;
// }