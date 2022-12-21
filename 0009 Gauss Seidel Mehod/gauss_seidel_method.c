// Write a program in “C” Language to find the solution of Linear Equation using Gauss Seidel Method.

#include <stdio.h>
#include <math.h>

int n, flag = 0;
float e;

float findSum(int i, float arr[n][n + 1])
{
    float sum = 0;
    for (int j = 0; j < n; j++)
    {
        if (i != j)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

int isMethodApplicable(float arr[n][n + 1])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fabs(arr[i][i]) > findSum(i, arr))
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

void print(int iteration, float values[n])
{
    printf("Iteration %d ", iteration);
    for (int i = 0; i < n; i++)
    {
        printf("value[%d]=%f ", i + 1, values[i]);
    }
    printf("\n");
}

void findValues(float a[][n + 1], int maxIterations, float values_old[n])
{
    int iteration;
    float sum = 0;
    float values_new[n];
    for (int i = 0; i < n; i++)
    {
        values_new[i] = 0;
    }
    for (iteration = 1; iteration < maxIterations; iteration++)
    {
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum += a[i][j] * values_new[j];
                }
            }
            values_new[i] = (a[i][n] - sum) / a[i][i];
        }
        for (int k = 0; k < n; k++)
        {
            if (fabs(values_old[k] - values_new[k]) < e)
            {
                continue;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("\nFinal Answer : ");
            print(iteration, values_new);
            return;
        }
        flag = 0;
        print(iteration, values_new);
        for (int k = 0; k < n; k++)
        {
            values_old[k] = values_new[k];
        }
    }
    print(iteration, values_new);
}

int main()
{
    int maxIterations;

    printf("Enter the number of rows : ");
    scanf("%d", &n);

    printf("Enter the value of allowed error : ");
    scanf("%f", &e);

    printf("Enter the maximum of iterations : ");
    scanf("%d", &maxIterations);

    float arr[n][n + 1], values[n];

    printf("Enter the arbitary matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }
    if (!isMethodApplicable(arr))
    {
        printf("Gauss Seidel method cannot be applied.\n");
        return 0;
    }

    printf("Gauss Seidel method is Applicable\n");
    for (int i = 0; i < n; i++)
    {
        values[i] = 0;
    }

    findValues(arr, maxIterations, values);

    return 0;
}