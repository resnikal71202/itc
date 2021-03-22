#include <stdio.h>
#include "condition.h"
#include "condition_probability.h"

int main(int argc, char **argv)
{
    struct condition con[3];
    for (size_t i = 0; i < sizeof(con) / sizeof(con[0]); i++)
    {
        init_condition(&con[i]);
    }

    add_connection(&con[0], &con[1], 0.5);
    add_connection(&con[0], &con[2], 0.5);
    add_connection(&con[1], &con[0], 0.5);
    add_connection(&con[1], &con[1], 0.5);
    add_connection(&con[2], &con[1], 0.5);
    add_connection(&con[2], &con[2], 0.5);

    double *pv;
    pv = p(con, sizeof(con) / sizeof(con[0]));

    printf("p(1):%f, p(2):%f, p(3):%f\n", pv[0], pv[1], pv[2]);

    free(pv);
    for (size_t i = 0; i < sizeof(con) / sizeof(con[0]); i++)
    {
        deinit_condition(&con[i]);
    }
    return 0;
}