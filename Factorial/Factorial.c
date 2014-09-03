#include "Factorial.h"

int calculoFactorial(int n)
{
    int i;

    for(i= (n - 1); i>1 ; i--)
    {
        n *= i;
    }

    return(n);
}

