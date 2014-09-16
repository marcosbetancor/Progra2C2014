#include "Combinatorio.h"
#include "Factorial.h"

int calculoCombinatorio(int m,int n,mfact,nfact)
{
    return((mfact)/(nfact*(calculoFactorial(m-n))));
}
