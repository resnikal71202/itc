#include <stdio.h>
#include "condition.h"

int main(int argc, char **argv)
{
    struct condition con[4];
    for (size_t i = 0; i < sizeof(con) / sizeof(con[0]); i++)
    {
        init_condition(&con[i]);
        printf("this: %x\n", &con[i]);
    }

    add_connection(&con[0], &con[1], 0.3);
    printf("added con\n");
    add_connection(&con[1], &con[2], 0.1);
    printf("added con\n");
    add_connection(&con[3], &con[0], 0.6);
    printf("added con\n");
    for (int i = 0; i < 100000; i++)
    {
        add_connection(&con[3], &con[3], 0.1);
        printf("connectet to : %x\n", con[3].connetion[i].to);
        printf("%d value : %ff\n", i, con[3].connetion[i].value);
    }

    add_connection(&con[3], &con[3], 0.1); // Woher kommt der Speicher???

    for (size_t i = 0; i < sizeof(con) / sizeof(con[0]); i++)
    {
        printf("connectet to : %x\n", con[i].connetion[0].to);
        printf("value : %ff\n", con[i].connetion[0].value);
    }
    printf("connectet to : %x\n", con[3].connetion[1].to);
    printf("value : %ff\n", con[3].connetion[1].value);
}