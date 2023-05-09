#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *my_thread_func(void *arg)
{
    printf("Thread created successfully\n");
    return NULL;
}

int main()
{
    pthread_t my_thread;
    printf("Before thread creation\n");
    // thread address, thread attributes, thread function, thread function arguments
    pthread_create(&my_thread, NULL, my_thread_func, NULL);

    pthread_join(my_thread, NULL);
    printf("After thread completion\n");
    return 0;
}