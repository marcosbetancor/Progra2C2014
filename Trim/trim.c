#include "trim.h"

rTrim(char *s, char c)
{
    char *aux = s;

    while(*aux)
        aux++;
    aux--;

    while(aux >= s && *aux==c)
        aux--;
    aux++;
    *aux= '\0';
    return 1;

}
