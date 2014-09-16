#include <stdio.h>
#include <stdlib.h>
#include "Factorial.h"

int main()
{
    int m,
        n,
        mfact,
        nfact;

    printf("Ingrese valor de "M":  ");
    scanf("%d",&m);
    printf("\nIngrese valor de "N":  ");
    scanf("%d",&n);
    mfact = calculoFactorial(m);
    nfact = calculoFactorial(n);
    numcomb = calculoCombinatorio(m,n,mfact,nfact);

    puts(numcomb);

    return 0;
}
