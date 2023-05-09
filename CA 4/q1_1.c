// implement IPC using message queue
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512

// array to store messages
char text[MAX_TEXT];

int main()
{
    int a = 1;
    // creating a new message queue
    int message_id = msgget((key_t)1999, 0666 | IPC_CREAT);

    char temp_arr[100];

    // checking if message queue is successfully created
    if (message_id == -1)
    {
        printf("Error in creating queue\n");
        exit(0);
    }

    while (a)
    {
        printf("Enter message : ");
        // read message from console
        fgets(temp_arr, 100, stdin);

        // copy message
        strcpy(text, temp_arr);

        if (msgsnd(message_id, (void *)&text, MAX_TEXT, 0) == -1)
            printf("Msg not sent\n");

        // condition to end the while loop when user enters exit
        if (strncmp(temp_arr, "exit", 4) == 0)
            a = 0; // make while loop condition false
    }

    return 0;
}