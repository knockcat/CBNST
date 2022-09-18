// Write a program in “C” Language to find out the root of the Algebraic and Transcendental equations using Iteration Method.

#include <stdio.h>
#include <math.h>
#define f(x) cos(x) - (3 * x) + 1
#define o(x) (cos(x) + 1) / 3.0
#define O(x) (-sin(x) / 3.0)
// #define f(x) (2*x)-log10(x)-7

int main()
{
    float x0, x1, e;
    int i = 0;

    printf("Enter the value of x0 : ");
    scanf("%f", &x0);

    printf("Enter the value of allowed error : ");
    scanf("%f", &e);

    if (fabs(O(x0)) < 1)
    {
        printf("Roots Found\n");
    }
    else
    {
        printf("Wrong value of x0\n");
        return 0;
    }

    while (1)
    {
        x1 = o(x0);
        ++i;
        printf("Root at Iteration %d = %f\n", i, x1);
        if (fabs(x0 - x1) < e)
        {
            printf("Root at iteration %d = %f\n", i, x1);
            break;
        }
        x0 = x1;
    }
}