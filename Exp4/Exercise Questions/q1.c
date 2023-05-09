
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

// wap using directory system calls make a directory in desktop and create a file inside the directory and list the contents of the directory.
int main()
{
    int check;

    char *dirname = "Dir1";

    check = mkdir(dirname, 0777);

    if (!check)
        printf("Directory created successfully\n");
    else
        printf("Directory already exists\n");

    FILE *fp;
    fp = fopen("Dir1/file.txt", "w");
    fprintf(fp, "This is a file created by C program");
    fclose(fp);

    system("ls Dir1");
    return 0;
}