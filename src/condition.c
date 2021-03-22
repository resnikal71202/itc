#include <stdlib.h>
#include "condition.h"

int init_condition(struct condition *condition)
{
    condition->connetion = malloc(sizeof(condition->connetion));
    condition->number_of_connetions = 0;
    condition->connetion->to = NULL;
    return 0;
}

int add_connection(struct condition *from, struct condition *to, double value)
{
    from->number_of_connetions++;
    from->connetion = realloc(from->connetion, sizeof(from->connetion[0]) * (from->number_of_connetions + 1));
    struct connetion *con_ptr = &from->connetion[from->number_of_connetions - 1];
    con_ptr->to = to;
    con_ptr->value = value;
    return 0;
}

int deinit_condition(struct condition *condition)
{
    free(condition->connetion);
    return 0;
}