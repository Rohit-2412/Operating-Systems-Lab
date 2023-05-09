#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define maxItems 2
#define bufferSize 2

// semaphore for empty
sem_t empty;
// semaphore for full
sem_t full;

// index for input
int in = 0;
// index for output
int out = 0;

// array to store the products
int buffer[bufferSize];

// mutex
pthread_mutex_t mutex;

int element = 100;
void *producer_fun(void *param)
{
    for (int i = 0; i < maxItems; i++)
    {
        int item = rand() % 100; // Produce a random item between 0 and 100

        sem_wait(&empty); // wait for semaphore

        // acquire lock
        pthread_mutex_lock(&mutex);
        buffer[in] = item; // place item into buffer

        // display the inserted item
        printf("Producer %d: Insert Item %d at %d\n", *((int *)param), buffer[in], in);

        // increase the index for next item
        in = (in + 1) % bufferSize;

        // unlock the mutex
        pthread_mutex_unlock(&mutex);

        // signal to semaphore
        sem_post(&full);
    }

    return NULL;
}

// function for consumer
void *consumer_fun(void *param)
{
    for (int i = 0; i < maxItems; i++)
    {
        // wait for semaphore
        sem_wait(&full);

        pthread_mutex_lock(&mutex);

        int item = buffer[out]; //  get the item

        printf("Consumer %d: Remove Item %d from %d\n", *((int *)param), item, out);

        out = (out + 1) % bufferSize; // increment the output index
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    return NULL;
}

int main()
{
    pthread_t p[bufferSize], c[bufferSize];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, bufferSize);

    int arr[bufferSize] = {1, 2};

    for (int i = 0; i < bufferSize; i++)
        pthread_create(&p[i], NULL, (void *)producer_fun, (void *)&arr[i]);

    for (int i = 0; i < bufferSize; i++)
        pthread_create(&c[i], NULL, (void *)consumer_fun, (void *)&arr[i]);

    for (int i = 0; i < bufferSize; i++)
        pthread_join(p[i], NULL);

    for (int i = 0; i < bufferSize; i++)
        pthread_join(c[i], NULL);

    return 0;
}