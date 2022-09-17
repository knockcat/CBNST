#include <stdio.h>
#include <math.h>

float fun(float x)
{
    return (x * x * x - 5 * x + 1);
    // return (x - cos(x));
}

int main()
{
    float a, b;
    float all;

    // printf("(x*x*x - 5*x + 1)\n");
    printf("(x - cos(x))\n");
    printf("Enter the first value: \n");
    scanf("%f", &a);
    printf("Enter the second value: \n");
    scanf("%f", &b);

    printf("Enter the allowed error: \n");
    scanf("%f", &all);

    if (fun(a) * fun(b) < 0)
    {
        printf("Roots are %f and %f \n", a, b);
    }

    else
    {
        printf("Wrong answer, try again \n");
    }

    float root;
    int count = 0;

    do
    {
        ++count;
        root = (a + b) / 2;
        if (fun(a) * fun(root) < 0)
        {
            b = root;
        }
        else
        {
            a = root;
        }

        printf("Iteration no %d: root value is : %f at a = %f and b = %f\n", count, root, a, b);
    } while (fabs(fun(root)) > all);
    return 0;
}