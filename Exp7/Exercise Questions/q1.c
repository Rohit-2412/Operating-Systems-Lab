/*
implement the producer consumer problem using pthreads and mutex operations
test cases:
a) a producer only produces if buffer is empty and a consumer only consumes items if some contents is in the buffer
b) a producer produces(writes) an item in the buffer and consumer consumes(deletes) the last produces item in the buffer.
c) a producer produces(writes) on the last consumed(deleted) index of the buffer
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define maxItems 5   // Maximum items a producer can produce or a consumer can consume
#define bufferSize 3 // Size of the buffer

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[bufferSize];
pthread_mutex_t mutex;

int element = 100;
void *producer_fun(void *param)
{
    int item = element++;
    for (int i = 0; i < maxItems; i++)
    {
        // item = rand(); // Produce a random item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)param), buffer[in], in);
        in = (in + 1) % bufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    return NULL;
}

void *consumer_fun(void *param)
{
    for (int i = 0; i < maxItems; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n", *((int *)param), item, out);
        out = (out + 1) % bufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    return NULL;
}

int main()
{
    pthread_t pro[bufferSize], con[bufferSize];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, bufferSize);
    sem_init(&full, 0, 0);

    int arr[bufferSize] = {1, 2, 3}; // used for numbering the producer and consumer

    for (int i = 0; i < bufferSize; i++)
    {
        pthread_create(&pro[i], NULL, (void *)producer_fun, (void *)&arr[i]);
    }
    for (int i = 0; i < bufferSize; i++)
    {
        pthread_create(&con[i], NULL, (void *)consumer_fun, (void *)&arr[i]);
    }

    for (int i = 0; i < bufferSize; i++)
    {
        pthread_join(pro[i], NULL);
    }
    for (int i = 0; i < bufferSize; i++)
    {
        pthread_join(con[i], NULL);
    }

    return 0;
}