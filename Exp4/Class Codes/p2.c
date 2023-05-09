#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;

    // variable to store the name of the directory to be created
    struct dirent *directory;

    // open the current directory
    dir = opendir(".");

    // if dir is not NULL, then it is a valid directory
    if (dir)
    {
        while ((directory = readdir(dir)) != NULL)
            printf("%s\n", directory->d_name);

        // close the directory
        closedir(dir);
    }
    return 0;
}