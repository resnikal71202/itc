#ifndef CONDITION_H
#define CONDITION_H
#include <stdbool.h>

struct connetion{
    struct condition *to;
    double *value;
};

struct condition
{
    char *name;
    bool value;
    struct connetion *connetion;
};

#endif