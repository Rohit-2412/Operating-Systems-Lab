#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    // variable to store the return value of mkdir
    int check;

    // variable to store the name of the directory to be created
    char *dirname = "Dir1";

    check = mkdir(dirname, 0777);

    if (!check)
        printf("Directory created successfully\n");
    else
        printf("Directory already exists\n");

    // list the files in the current directory
    system("ls");

    return 0;
}