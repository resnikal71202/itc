#include "condition.h"
#include <stdlib.h>
// #include <stdio.h>

double *gauss_elimination(double **A, int n)
{
    double c, sum;
    double *x = malloc((n + 1) * sizeof(double));
    // printf("malloced\n");
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > j)
            {
                c = A[i][j] / A[j][j];
                for (int k = 0; k < n + 1; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n] - sum) / A[i][i];
    }
    return x;
}

double *p(struct condition *A, int number_of_conditions)
{
    double **arr = malloc(sizeof(double *) * number_of_conditions);
    for (int i = 0; i < number_of_conditions; i++)
    {
        arr[i] = malloc(sizeof(double) * (number_of_conditions + 1));
    }
    //zero
    for (int y = 0; y < number_of_conditions - 1; y++)
    {
        for (int x = 0; x < number_of_conditions; x++)
        {
            arr[y][x] = 0.0;
        }
    }
    //add connections
    for (int x = 0; x < number_of_conditions; x++)
    {
        for (int i = 0; i < number_of_conditions; i++)
        {
            for (size_t j = 0; j < A[i].number_of_connetions; j++)
            {
                if (A[i].connetion[j].to == &A[x])
                {
                    arr[x][i] += A[x].connetion[j].value;
                    // printf("add[%d][%d] += %f\n", x, i, A[x].connetion[j].value);
                }
            }
        }
    }
    //minus it self
    for (int y = 0; y < number_of_conditions - 1; y++)
    {
        for (int x = 0; x < number_of_conditions; x++)
        {
            if (x == y)
                arr[y][x] -= 1.0;
            // printf("arr[%d][%d] = %f\n", y, x, arr[y][x]);
        }
        arr[y][number_of_conditions] = 0.0;
        // printf("arr[%d][%d] = %f\n", y, number_of_conditions, 0.0);
    }
    //add last row of 1
    for (int x = 0; x < number_of_conditions + 1; x++)
    {
        arr[number_of_conditions - 1][x] = 1.0;
        // printf("arr[%d][%d] = %f\n", number_of_conditions - 1, x, arr[number_of_conditions - 1][x]);
    }

    double *pout = gauss_elimination(arr, number_of_conditions);
    for (int i = 0; i < number_of_conditions; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return pout;
}