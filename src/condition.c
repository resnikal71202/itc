#include <stdlib.h>
#include "condition.h"
#include <stdio.h>

int init_condition(struct condition *condition)
{
    condition->connetion = malloc(sizeof(condition->connetion));
    condition->number_of_connetions = 0;
    condition->connetion->to = NULL;
    condition->value = 0;
    return 0;
}

int add_connection(struct condition *from, struct condition *to, double value)
{
    from->number_of_connetions++;
    printf("%x\n", from->connetion);
    from->connetion = realloc(from->connetion, sizeof(from->connetion[0]) * (from->number_of_connetions + 1));
    printf("%x\n", from->connetion);
    struct connetion *con_ptr = &from->connetion[from->number_of_connetions];
    con_ptr->to = to;
    con_ptr->value = value;
    // from->connetion = realloc(from->connetion, sizeof(from->connetion) * from->number_of_connetions);
    return 0;
}