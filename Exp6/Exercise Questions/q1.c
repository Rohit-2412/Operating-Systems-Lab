// write a program using pthread to concatenate the strings, where multiple strings are passed to thread function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void *func(void *arg);

char *result;
int num_of_strings = 0;
int main()
{
    char **strings;
    int i;

    printf("Enter the number of strings: ");
    scanf("%d", &num_of_strings);
    strings = (char **)malloc(sizeof(char *) * num_of_strings);
    for (i = 0; i < num_of_strings; i++)
    {
        strings[i] = (char *)malloc(sizeof(char) * 100);
        printf("Enter string %d: ", i + 1);
        scanf("%s", strings[i]);
    }

    result = (char *)malloc(sizeof(char) * 100);

    pthread_t thread;
    pthread_create(&thread, NULL, func, strings);
    pthread_join(thread, NULL);

    printf("Concatenated string is: %s\n", result);
}

void *func(void *arg)
{
    char **arr = (char **)arg;
    int i;
    for (i = 0; i < num_of_strings; i++)
    {
        strcat(result, arr[i]);
    }
    return NULL;
}