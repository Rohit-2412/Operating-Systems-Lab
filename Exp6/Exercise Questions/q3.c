// wap using pthread that perform statistical operation of calculating average, maximum and minimum of the array passed to the thread function. create 3 threads for each operation.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 5

void *average(void *arg);
void *maximum(void *arg);
void *minimum(void *arg);

int size = 0;
int main()
{
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *array = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    pthread_t threads[3];
    int i;
    pthread_create(&threads[0], NULL, average, array);
    pthread_create(&threads[1], NULL, maximum, array);
    pthread_create(&threads[2], NULL, minimum, array);

    for (i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    printf("\n");

    return 0;
}

void *average(void *arg)
{
    int *arr = (int *)arg;
    int sum = 0;
    int i;
    for (i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    int avg = sum / N;
    printf("Average: %d\n", avg);
    return NULL;
}

void *maximum(void *arg)
{
    int *arr = (int *)arg;
    int max = arr[0];
    int i;
    for (i = 1; i < N; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    printf("Maximum: %d\n", max);
    return NULL;
}

void *minimum(void *arg)
{
    int *arr = (int *)arg;
    int min = arr[0];
    int i;
    for (i = 1; i < N; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    printf("Minimum: %d\n", min);
    return NULL;
}