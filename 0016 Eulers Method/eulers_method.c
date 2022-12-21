// Write a program in “C” Language to find the numerical solution of ordinary differential equations by Euler’s Method.

#include <stdio.h>
#include <math.h>

#define f(x, y) (y - x) / (y + x);

int main()
{
    int n, i = 1;
    float xi, yi, x, y, h;

    printf("Enter the value of n : ");
    scanf("%d", &n);

    printf("Enter the initial condition for x and y : ");
    scanf("%f%f", &xi, &yi);

    printf("Enter the value of x for which y is needed : ");
    scanf("%f", &x);

    h = (x - xi) / n;

    while (xi < x && i <= n)
    {
        y = yi + h * f(xi, yi);
        yi = y;
        xi = xi + h;
        printf("x%d = %.4f\t y%d = %.4f\n", i, xi, i, yi);
        ++i;
    }

    printf("\nValue of y%d is = %.4f\n", i - 1, y);

    return 0;
}
