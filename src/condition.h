#ifndef CONDITION_H
#define CONDITION_H
#include <stddef.h>
#include <stdbool.h>

struct connetion
{
    struct condition *to;
    double value;
};

struct condition
{
    char *name;
    bool value;
    double p;
    size_t number_of_connetions;
    struct connetion *connetion;
    // size_t number_of_connetions_to;
    // struct connetion *connetion_to;
};

int init_condition(struct condition *condition);
int add_connection(struct condition *from, struct condition *to, double value);
int deinit_condition(struct condition *condition);
#endif