// q1 p2
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

char text[BUFSIZ];

int main()
{
    int a = 1;
    int message_id = msgget((key_t)1999, 0666 | IPC_CREAT);

    printf("Waiting for receiver\n");
    while (a)
    {
        msgrcv(message_id, (void *)&text, BUFSIZ, 0, 0);
        if (strncmp(text, "exit", 4) == 0)
            a = 0;
        printf("Received: %s", text);
    }

    msgctl(message_id, IPC_RMID, 0);
}