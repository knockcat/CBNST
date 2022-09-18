// Write a program in “C” Language to find out the root of the Algebraic and Transcendental equations using Regula Falsi Method.

#include <stdio.h>
#include <math.h>
#define f(x) (3 * x) + sin(x) - exp(x)

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int i = 0;

    printf("Enter the value of x0 : ");
    scanf("%f", &x0);

    printf("Enter the value of x1 : ");
    scanf("%f", &x1);

    printf("Enter the value of allowed error : ");
    scanf("%f", &e);

    if (f(x0) * f(x1) < 0)
    {
        printf("Roots Found\n");
    }
    else
    {
        printf("Wrong Interval\n");
        return 0;
    }

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        x2 = x0 - (((x1 - x0) / (f1 - f0)) * f0);
        f2 = f(x2);
        if (f0 * f2 < 0)
        {
            x1 = x2;
        }
        else
        {
            x0 = x2;
        }
        ++i;

        printf("No of Iteration = %d and Root = %f\n", i, x2);
    } while (fabs(f2) > e);

    printf("\nFinal root after %d iteration = %f", i, x2);

    return 0;
}