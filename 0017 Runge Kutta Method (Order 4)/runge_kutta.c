// Write a program in “C” Language to find the numerical solution of ordinary differential equations by Runge Kutta (Order 4) Method.

#include <stdio.h>
#include <math.h>

#define f(x, y) (y * y - x * x) / (y * y + x * x)

int main()
{
    int i = 1;
    float x0, y0, k1, k2, k3, k4, k, y, x, h, xn;

    printf("Enter x0, y0 & h : ");
    scanf("%f%f%f", &x0, &y0, &h);

    x = x0;
    y = y0;

    printf("Enter x for which y has to be found : ");
    scanf("%f", &xn);

    while (x < xn)
    {
        k1 = f(x0, y0);
        k2 = f((x0 + h / 2.0), (y0 + k1 * h / 2.0));
        k3 = f((x0 + h / 2.0), (y0 + k2 * h / 2.0));
        k4 = f((x0 + h), (y0 + k3 * h));
        k = ((k1 + 2 * k2 + 2 * k3 + k4) / 6);
        y = y + k * h;
        x = x + h;
        printf("x%d = %.4f\ty%d = %.4f\n", i, x, i, y);
        ++i;
    }

    printf("\nValue of y%d is : %.4f\n", i - 1, y);

    return 0;
}