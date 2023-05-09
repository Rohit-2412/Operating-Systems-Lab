// Write a multithreaded program where an array of integers is passed globally and is divided into two smaller lists and given as input to two threads. The thread will sort their half of the list and will pass the sorted list to a third thread which merges and sorts the list. The final sorted list is printed by the parent thread.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 3

void *merge(void *arg);
void *sort(void *arg);

int main()
{
    int i;
    int *array = (int *)malloc(sizeof(int) * 10);
    for (i = 0; i < 10; i++)
    {
        array[i] = rand() % 100;
    }

    // display array
    printf("Original array: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, sort, array);
    pthread_create(&threads[1], NULL, sort, array + 5);
    pthread_create(&threads[2], NULL, merge, array);

    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("Sorted array: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void *merge(void *arg)
{
    int *arr = (int *)arg;
    int i, j, k;
    int temp[10];
    i = 0;
    j = 5;
    k = 0;
    while (i < 5 && j < 10)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i < 5)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j < 10)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (i = 0; i < 10; i++)
    {
        arr[i] = temp[i];
    }
    return NULL;
}

void *sort(void *arg)
{
    int *arr = (int *)arg;
    int i, j, temp;
    for (i = 0; i < 5; i++)
    {
        for (j = i + 1; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return NULL;
}