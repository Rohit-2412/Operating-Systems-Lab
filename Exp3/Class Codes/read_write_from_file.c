#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main()
{
    // write(1, "system Call Session\n", 20);

    // int count;
    // count = write(1, "System call session", 19);
    // printf("\nThe data written is % d bytes", count);
    // printf("\n");

    /* reading data from console and displaying it on console*/
    int r;
    // array to store the 50 bytes of data
    char buf[50];
    // read (file descriptor, buffer, size)
    // return the number of bytes read //
    // r = read(0, &buf, 10);

    // display the data read //
    // write(1, buf, r);

    /** writing some data to file **/

    // open a file, if not present create it
    // open() will return a file descriptor
    // 0777 is the permission to the file
    /*
    0 is for octal number
    7 represents read, write and execute permission for the owner of the file
    7 represents read, write and execute permission for the group of the file
    7 represents read, write and execute permission for the others
    */
    // O_CREAT is the flag to create the file
    // O_WRONLY is the flag to open the file in write mode
    // int fd = open("demo.txt", O_WRONLY | O_CREAT, 0777);

    // write the data to the file
    // data: "Writing to a file demonstration"
    // size: 25 bytes
    // write(fd, "Writing to a file demonstration", 25);
    // success message //
    // printf("Successfully written to the file");

    /** copying data from one file to another **/
    char buf2[50];
    // opening the first file in read mode
    int fd2 = open("first.txt", O_RDONLY, 0777);

    // opening the second file in write mode
    int fd3 = open("second.txt", O_WRONLY | O_CREAT, 0777);
    // using a while loop and read() to read 1 byte at a time
    // and writing it to the file
    while (read(fd2, &buf2, 1) != 0)
    {
        write(fd3, buf2, 1);
    }
    // closing the files
    close(fd2);
    close(fd3);
    // success message
    // printf("copy successful from first file to second file");

    // ** Appending some content to the file ** //
    char buf3[50];
    int fd4 = open("demo.txt", O_WRONLY | O_APPEND, 0777);
    int content_length = read(0, &buf3, 50);
    write(fd2, buf3, content_length);
    printf("APPEND SUCCESSFUL");

    return 0;
}
