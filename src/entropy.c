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

double pverbund(struct condition *A, struct condition *B)
{
    double pverbund = 0;
    for (size_t i = 0; i < A->number_of_connetions; i++)
    {
        if (A->connetion[i].to == B)
        {
            pverbund += A->connetion[i].value * A->p;
        }
    }
    return pverbund;
}

double Hb(struct condition *A, size_t array_size)
{
    double H = 0;
    for (size_t i = 0; i < array_size; i++)
    {
        for (size_t j = 0; j < A[i].number_of_connetions; j++)
        {
            // printf("%f (-ld(%f))\n", pverbund(&A[i], A[i].connetion[j].to), A[i].connetion[j].value);
            H -= pverbund(&A[i], A[i].connetion[j].to) * log2(A[i].connetion[j].value);
        }
    }
    return H;
}