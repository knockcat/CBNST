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

/*
// Write a program in “C” Language to find out the root of the Algebraic and Transcendental equations using Bisection Method. 
#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x)-(5*x)+1
int main()
{
    float x0,x1,x2,f0,f1,f2,e;
    int i=0;
    printf("Enter the value of x0 : ");
    scanf("%f",&x0);
    printf("Enter the value of x1 : ");
    scanf("%f",&x1);
    printf("Enter the allowed error : ");
    scanf("%f",&e);
    if(f(x0)*f(x1)<0)
    {
        printf("Roots found\n");
    }
    else
    {
        printf("Wrong interval\n");
        return 0;
    }
    do
    {
        f0=f(x0);
        f1=f(x1);
        x2=(x0+x1)/2;
        f2=f(x2);
        if(f0*f2<0)
        {
            x1=x2;
        }
        else
        {
            x0=x2;
        }
        i++;
        printf("No of iteration = %d ",i);
        printf("and Root = %f\n",x2);
    }while(fabs(f2)>e);
    printf("\nFinal root after %d iteration = %f\n",i,x2);
    return 0;
}
*/