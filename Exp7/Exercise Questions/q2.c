// reader writer problem using semaphores and mutex operations To synchronize and readers active in the reader section at a same time and one reader active at a time
// test cases
// 1. if n readers are active, no writer is allowed to write
// 2. if one writer is writing, no other writer should be allowed to read or write on the shared variable

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int numOfReader = 0;

void *writer(void *param)
{
    sem_wait(&wrt);
    cnt = cnt * 2;
    printf("Writer %d modified cnt to %d\n", *((int *)param), cnt);
    sem_post(&wrt);
    return NULL;
}

void *reader(void *param)
{
    pthread_mutex_lock(&mutex);
    numOfReader++;
    if (numOfReader == 1)
    {
        sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    printf("Reader %d: read cnt as %d\n", *((int *)param), cnt);
    pthread_mutex_lock(&mutex);
    numOfReader--;
    if (numOfReader == 0)
    {
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    pthread_t reader_arr[10], writer_arr[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Just used for numbering the producer and consumer

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&reader_arr[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&writer_arr[i], NULL, (void *)writer, (void *)&a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(reader_arr[i], NULL);
    }
    for (int i = 0; i < 5; i++)
    {
        pthread_join(writer_arr[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return 0;
}