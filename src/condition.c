#include <stdlib.h>
#include "condition.h"

int init_condition(struct condition *condition){
    condition->number_of_connetions = 0;
    condition->connetion = malloc(sizeof(struct condition *));
    condition->connetion[0] = NULL;
    // condition->name = "Olaf";
    // condition->value = 0;
    return 0;
}

int add_connection(struct condition *from, struct condition *to){
    // printf("from : %d , to : %d\n", from, to);
    from->number_of_connetions++;
    // printf("from->number_of_cons: %d\n", from->number_of_connetions);
    from->connetion = realloc(from->connetion, sizeof(from->connetion) * from->number_of_connetions);
    from->connetion[from->number_of_connetions - 1] = to;
    // printf("from_to_ptr : %d\n", from->connetion[from->number_of_connetions - 1]);
    return 0;
}