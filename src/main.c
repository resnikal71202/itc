#include <stdio.h>
#include "condition.h"

int main(int argc, char **argv)
{
    struct condition con[4];
    for (size_t i = 0; i < sizeof(con)/sizeof(con[0]); i++)
    {
        init_condition(&con[i]);
        printf("this: %d\n", &con[i]);
    }

    add_connection(&con[0], &con[1]);
    printf("added con\n");
    add_connection(&con[1], &con[2]);
    printf("added con\n");
    add_connection(&con[3], &con[0]);
    printf("added con\n");

    for (size_t i = 0; i < sizeof(con) / sizeof(con[0]); i++)
    {
        printf("connectet to : %d\n", con[i].connetion[0]);
    }
}