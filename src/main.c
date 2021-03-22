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

    double *pa;
    pa = p(con, 3);
    printf("%f, %f, %f\n", pa[0], pa[1], pa[2]);
    return 0;
}