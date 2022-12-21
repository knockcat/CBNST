// Write a program in “C” Language to find the solution of Linear Equation using Gauss Elimination Method.

#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of rows : ");
    scanf("%d", &n);

    float arr[n][n + 1], value[n];
    float ratio;

    printf("Enter the arbitary matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
            {
                ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] -= (ratio * arr[i][k]);
                }
            }
        }
    }

    printf("\nUpper triangular Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%0.1f\t", arr[i][j]);
        }
        printf("\n");
    }

    value[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        float sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += arr[i][j] * value[j];
        }
        value[i] = (arr[i][n] - sum) / arr[i][i];
    }

    printf("\nThe value are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("value[%d] = %0.1f\n", i, value[i]);
    }

    printf("\n");
    return 0;
}