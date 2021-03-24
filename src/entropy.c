#include <math.h>
#include <stddef.h>

double H(double *pv, int array_size)
{
    double sum = 0.0;
    for (int i = 0; i < array_size; i++)
    {
        sum += -pv[i] * log2(pv[i]);
    }
    return sum;
}