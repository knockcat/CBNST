// Write a program in “C” Language to interpolate numerically using Lagrange’s Method.

#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of temrs : ");
    scanf("%d", &n);

    float X[n], Y[n], x, sum = 0, term;

    printf("Enter the values of X : ");
    for (int i = 0; i < n; ++i)
        scanf("%f", &X[i]);

    printf("Enter the values of Y : ");
    for (int i = 0; i < n; ++i)
        scanf("%f", &Y[i]);

    printf("Enter the value of x for which you want to find the value of y : ");
    scanf("%f", &x);

    for (int i = 0; i < n; ++i)
    {
        term = 1;
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
                term = term * ((x - X[j]) / (X[i] - X[j]));
        }
        sum = sum + term * Y[i];
    }

    printf("\nValue of Y at x = %g is = %f\n", x, sum);

    return 0;
}