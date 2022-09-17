#include <stdio.h>
#include <math.h>

int main()
{
    float trueValue, approximateValue, absoluteError, relativeError, percentageError;

    printf("Enter True Value : ");
    scanf("%f", &trueValue);

    printf("Enter Approximate Value : ");
    scanf("%f", &approximateValue);

    absoluteError = fabs(trueValue - approximateValue);
    relativeError = fabs(absoluteError / trueValue);
    percentageError = relativeError * 100;

    printf("Absolute Error : %f\n", absoluteError);
    printf("Relative Error : %f\n", relativeError);
    printf("Percentage Error %f\n ", percentageError);

    return 0;
}