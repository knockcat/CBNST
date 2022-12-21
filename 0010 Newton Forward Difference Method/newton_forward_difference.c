// Write a program in “C” Language to interpolate numerically using Newton Forward Difference Method.

#include <stdio.h>
#include <math.h>

#define max 100

int main()
{
    float x, u1, u, y;
    int n, fact;

    printf("Enter the number of terms : ");
    scanf("%d", &n);

    float arr[n][n + 1];

    printf("Enter the value of X : ");
    for (int i = 0; i < n; ++i)
        scanf("%f", &arr[i][0]);

    printf("Enter the value of Y : ");
    for (int i = 0; i < n; ++i)
        scanf("%f", &arr[i][1]);

    printf("\nEnter the value of x for which you want y : ");
    scanf("%f", &x);

    // Find The Difference Table
    for (int j = 2; j < n + 1; ++j)
    {
        for (int i = 0; i < n - j + 1; ++i)
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];
    }

    printf("The difference Table is as Follows : \n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= n - i; ++j)
            printf("%0.2f\t\t", arr[i][j]);
        printf("\n");
    }

    u = (x - arr[0][0]) / (arr[1][0] - arr[0][0]);
    y = arr[0][1];
    u1 = u;
    fact = 1;
    for (int i = 2; i <= n; ++i)
    {
        y = y + (u1 * (arr[0][i])) / fact;
        fact *= i;
        u1 = u1 * (u - (i - 1));
    }

    printf("\n\nValue at X = %.2f is = %f \n", x, y);

    return 0;
}