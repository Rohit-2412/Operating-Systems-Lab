// wap to create two threads one will print 1 to 10 and other will find if number is even or odd

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *print(void *arg)
{
    int i;
    printf("Displaying number from 1 to 10\n");
    for (i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    return NULL;
}

void *even_odd(void *arg)
{
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    if (i % 2 == 0)
        printf("%d is even\n", i);
    else
        printf("%d is odd\n", i);

    return NULL;
}

// check armstrong number
void *armstrong(void *arg)
{
    int n, r, sum = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &n);
    temp = n;
    while (n > 0)
    {
        r = n % 10;
        sum = sum + (r * r * r);
        n = n / 10;
    }
    if (temp == sum)
        printf("%d is an Armstrong number\n", temp);
    else
        printf("%d is not an Armstrong number\n", temp);

    return NULL;
}

// check prime number
void *prime(void *arg)
{
    int n, i, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i <= n / 2; ++i)
    {
        // condition for non-prime
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (n == 1)
    {
        printf("1 is neither prime nor composite.\n");
    }
    else
    {
        if (flag == 0)
            printf("%d is a prime number.\n", n);
        else
            printf("%d is not a prime number.\n", n);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, print, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, even_odd, NULL);
    pthread_join(t2, NULL);
    return 0;
}