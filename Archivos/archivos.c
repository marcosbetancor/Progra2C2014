#include "archivos.h"

int abrirArchivo(FILE **fp, const char *nom, const char *modo, int conSin)
{
    *fp = fopen(nom, modo);

    if(*fp == NULL)
    {
        if(conSin == CON_MSJ)
            fprintf(stderr,"ERROR abriendo archivo\"%s\" enmodo \"%s\".\n",nom, modo);
        return 0;
    }
    return 1;
}
