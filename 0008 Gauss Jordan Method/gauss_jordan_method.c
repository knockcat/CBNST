// Write a program in “C” Language to find the solution of Linear Equation using Gauss Jordan Method.

#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    printf("Enter the number of rows : ");
    scanf("%d", &n);

    float arr[n][n + 1];
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
            if (j != i)
            {
                ratio = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; k++)
                {
                    arr[j][k] -= (ratio * arr[i][k]);
                }
            }
        }
    }

    printf("\nDiagonal Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            printf("%0.1f\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nThe value are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("value[%d] = %0.1f\n", i, arr[i][n] / arr[i][i]);
    }
    printf("\n");

    return 0;
}