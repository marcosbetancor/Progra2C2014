#include <stdio.h>
#include <stdlib.h>
#include "Factorial.h"
int main()
{   int num,
        numfact;

    printf("Ingrese número factorial ha averiguar: ");
    scanf("%d",&num);
    numfact = calculoFactorial(num);
    printf("\n\t\t\t%d! =  %d",num,numfact);

    return 0;
}
