#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    fork();
    fork();
    fork();
    printf("Process created\n");

    return 0;
}