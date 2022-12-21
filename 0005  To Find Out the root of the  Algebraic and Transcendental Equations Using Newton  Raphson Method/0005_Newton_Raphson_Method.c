// Write a program in “C” Language to find out the root of the Algebraic and Transcendental equations using Newton Raphson Method.

#include <stdio.h>
#include <math.h>

#define f(x) (3 * x) - cos(x) - 1
#define F(x) 3 + sin(x)

int main()
{
    float x0, x1, f0, f1, f2, e;
    int i = 0;

    printf("Enter the value of x0 : ");
    scanf("%f", &x0);
    printf("Enter the allowed error : ");
    scanf("%f", &e);

    do
    {
        f0 = f(x0);
        f1 = F(x0);
        if (f1 == 0)
        {
            printf("Method failed. ");
            return 0;
        }
        x1 = x0 - (f0 / f1);
        i++;
        printf("No of iteration = %d and Root = %f\n", i, x1);
        x0 = x1;
        f2 = f(x1);
    } while (fabs(f2) > e);

    printf("\nFinal root after %d iteration = %f\n", i, x1);

    return 0;
}