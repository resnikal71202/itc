#ifndef ENTROPY_H
#define ENTROPY_H
#include "condition.h"

double H(double *pv, int array_size);
double Hb(struct condition *A, int array_size);
#endif