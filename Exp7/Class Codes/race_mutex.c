#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *fun1();
void *fun2();
int shared = 1;       // shared variable
pthread_mutex_t lock; // mutex lock
int main()
{
    pthread_mutex_init(&lock, NULL); // initializing mutex locks
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final value of shared is %d\n", shared); // prints the last updated value of shared variable

    return 0;
}

void *fun1()
{
    int x;
    printf("Thread1 trying to acquire lock\n");
    pthread_mutex_lock(&lock); // thread one acquires the lock. Now thread 2 will not be able to acquire the lock //until it is unlocked by thread 1
    printf("Thread1 acquired lock\n");
    x = shared; // thread one reads value of shared variable
    printf("Thread1 reads the value of shared variable as %d\n", x);
    x *= 10; // thread one multiplies the value of shared variable by 10
    printf("Local updation by Thread1: %d\n", x);
    sleep(1);   // thread one is preempted by thread 2
    shared = x; // thread one updates the value of shared variable
    printf("Value of shared variable updated by Thread1 is: %d\n", shared);
    pthread_mutex_unlock(&lock);
    printf("Thread1 released the lock\n");
    return NULL;
}

void *fun2()
{
    int y;
    printf("Thread2 trying to acquire lock\n");
    pthread_mutex_lock(&lock);
    printf("Thread2 acquired lock\n");
    y = shared; // thread two reads value of shared variable
    printf("Thread2 reads the value as %d\n", y);
    y = 0; // thread two increments its value
    printf("Local updation by Thread2: %d\n", y);
    sleep(1);   // thread two is preempted by thread 1
    shared = y; // thread one updates the value of shared variable
    printf("Value of shared variable updated by Thread2 is: %d\n", shared);
    pthread_mutex_unlock(&lock);
    printf("Thread2 released the lock\n");
    return NULL;
}
