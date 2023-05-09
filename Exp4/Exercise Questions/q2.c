#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

// wap using directory system calls and file manipulation system calls to copy the contents of one directory in a newly created directory.
int main()
{
    DIR *dir;
    struct dirent *directory;
    dir = opendir("Dir1");

    int check;

    char *dirname = "Dir2";

    if (dir)
    {
        check = mkdir(dirname, 0777);
        if (!check)
            printf("Directory created successfully\n");
        else
            printf("Directory already exists\n");
    }
    else
    {
        printf("Directory does not exist\n");
    }

    if (dir)
    {
        while ((directory = readdir(dir)) != NULL)
        {
            printf("%s\n", directory->d_name);

            int fd1, fd2;
            fd1 = open("Dir1/file.txt", O_RDONLY);
            fd2 = open("Dir2/new_file.txt", O_CREAT | O_WRONLY, 0777);

            if (fd1 < 0)
            {
                printf("Error in opening file\n");
                exit(1);
            }
            if (fd2 < 0)
            {
                printf("Error in opening file\n");
                exit(1);
            }
            if (write(fd1, directory->d_name, strlen(directory->d_name)) < 0)
            {
                printf("Error in writing to file\n");
                exit(1);
            }

            // close file
            close(fd1);
            close(fd2);
        }
        closedir(dir);
    }

    return 0;
}