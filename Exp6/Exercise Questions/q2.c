// wap using pthread to find the length of the string passed to the thread function

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *thread_function(void *arg)
{
    char *s = (char *)arg;
    int len = strlen(s);
    s[len - 1] = '\0';
    printf("Length of the string '%s' is: %d\n", s, len);
    return NULL;
}

int main()
{
    char s[128];
    // ask user for the string
    printf("Enter the string: ");

    // read a line from stdin with spaces
    fgets(s, 128, stdin);

    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, s);
    pthread_join(thread, NULL);
    return 0;
}