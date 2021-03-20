#ifndef CONDITION_H
#define CONDITION_H
#include <stddef.h>
#include <stdbool.h>

struct connetion{
    struct condition *to;
    double *value;
};

struct condition
{
    char *name;
    bool value;
    size_t number_of_connetions;
    struct connetion **connetion;
};

int init_condition(struct condition *condition);
int add_connection(struct condition *from, struct condition *to);
#endif