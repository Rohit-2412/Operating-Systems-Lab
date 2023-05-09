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

#define maxItems 8   // Maximum items a producer can produce or a consumer can consume
#define bufferSize 5 // Size of the buffer

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[bufferSize];
pthread_mutex_t lock; // mutex lock

void *producer_fun(void *arg)
{
    int item = 100;
    for (int i = 0; i < maxItems; i++)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&lock);
        buffer[in] = item++;
        printf("Producer: Inserted Item %d at %d\n", buffer[in], in);
        in = (in + 1) % bufferSize;
        pthread_mutex_unlock(&lock);
        sem_post(&full);
    }

    return NULL;
}

void *consumer_fun(void *arg)
{
    for (int i = 0; i < maxItems; i++)
    {
        sem_wait(&full);
        pthread_mutex_lock(&lock);
        int item = buffer[out];
        buffer[out] = -1;
        printf("Consumer: Removed Item %d from %d\n", item, out);
        out = (out + 1) % bufferSize;
        pthread_mutex_unlock(&lock);
        sem_post(&empty);
    }

    return NULL;
}

int main()
{
    pthread_t producer, consumer;
    pthread_mutex_init(&lock, NULL);
    // address of semaphore, 0 for threads/(non zero for process), initial value
    sem_init(&empty, 0, bufferSize);
    sem_init(&full, 0, 0);

    pthread_create(&producer, NULL, (void *)producer_fun, NULL);
    pthread_create(&consumer, NULL, (void *)consumer_fun, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    return 0;
}