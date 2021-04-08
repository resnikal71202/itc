#include <math.h>
#include <stddef.h>
#include "condition.h"

double H(double *pv, int array_size)
{
    double sum = 0.0;
    for (int i = 0; i < array_size; i++)
    {
        sum += -pv[i] * log2(pv[i]);
    }
    return sum;
}

double Hb(struct condition *A, int array_size)
{
    double H = 0;
    for (int i = 0; i < array_size; i++)
    {
        // printf("array size %d \n", i);
        // for (int j = 0; j < A[i].number_of_connetions; j++)
        // {
        //     printf("A[%d].nucon %d\n", i, j);
        //     for (int k = 0; k < A[i].connetion[j].to->number_of_connetions; k++)
        //     {
        //         printf("%lf * %lf *(-ld(%lf))\n", A[i].connetion[j].to->connetion[k].value, A[i].p, A[i].connetion[j].to->connetion[k].value);
        //         H += A[i].connetion[j].to->connetion[k].value * A[i].p * (-log2(A[i].connetion[j].to->connetion[k].value));
        //     }
        //     // H += A[i].connetion[j].value * A[i].connetion[j].to->p * (-log2(A[i].connetion[j].value));
        // }
        printf("A[%d]\n", i);
        for (int j = 0; j < A[i].number_of_connetions; j++)
        {
            printf("A[%d].connetion[%d]\n", i, j);
            printf("%lf * %lf *(-ld(%lf))\n", A[i].connetion[j].value, A[i].connetion[j].to->p, A[i].connetion[j].value);
            H += A[i].connetion[j].value * A[i].connetion[j].to->p * (-log2(A[i].connetion[j].value));
        }
    }
    return H;
}