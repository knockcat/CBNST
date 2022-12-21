// Write a program in "C" Language for Linear Curve Fitting

#include <stdio.h>

int main()
{
    int n;
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, a, b;

    printf("Enter no. of points : ");
    scanf("%d", &n);

    float x[n], y[n], table[2][3];

    printf("Enter values of x : ");
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter values of y : ");

    for (int i = 0; i < n; i++)
        scanf("%f", &y[i]);

    // Computations
    for (int i = 0; i < n; i++)
    {
        sum1 = sum1 + x[i];
        sum2 = sum2 + y[i];
        sum3 = sum3 + x[i] * y[i];
        sum4 = sum4 + x[i] * x[i];
    }

    // finding slope and intercept
    table[0][0] = n;
    table[0][1] = sum1;
    table[0][2] = sum2;
    table[1][0] = sum1;
    table[1][1] = sum4;
    table[1][2] = sum3;

    // solving it
    int ratio = table[1][0] / table[0][0];
    for (int i = 0; i < 3; i++)

        table[1][i] = table[1][i] - ratio * table[0][i];

    // printing Upper Triangular matrix
    printf("\nThe Upper Triangular Matrix :-\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%.2f ", table[i][j]);
        printf("\n");
    }

    // finding a and b by back substitution (a = intercept , b = slope)
    b = table[1][2] / table[1][1];
    a = (table[0][2] - table[0][1] * b) / table[0][0];

    printf("\nIntercept = %.2f and Slope = %.2f\n\n", a, b);

    // Output
    printf("Equation: y= %.2f + %.2fx\n", a, b);

    return 0;
}