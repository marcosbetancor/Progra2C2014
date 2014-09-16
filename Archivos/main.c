#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"

int main()
{
    FILE *fpEnt,
         *fpSal1,
         *fpSal2;

    t_pers reg:

    //crearArchivo();

    /*fpEnt = fopen(ARCH_DATOS, "rb");     SE CAMBIA POR LODE ABAJO!!

    if(fpEnt == null)
    {
        fprint(stderr,"ERROR abriendo\"%s\"en modo " \"rb\", ARCH_DATOS);
        return 1;
        exit(1);
    } */


    if(!abrirArchivo(&fpEnt, ARCH_DATOS, "rb", con_msj))
        return 1;

    if(!abrirArchivo(&fpSal1, SAlIDA1, "wt", con_msj))
    {
        fclose(fpEnt);
        return 2;
    }

    if(!abrirArchivo(&fpSal2, SALIDA2, "wt", con_msj))
    {
        fclose(fpEnt);
        fclose(fpSal1);
        return 4;
    }

    fread(&reg, sizeof(t_pers), 1, fpEnt);

    while(!feof(fpEnt))
    {
        fprintf(fpSal1,"%ld\t%s\t%s\t%c\n", reg.dni, reg.ape, reg.nom, reg.sex); //*s sirve para tener argumento reemplazable.
        fprintf(fpSal2,"%08ld%-36s%-41s%c\n", reg.dni, reg.ape, reg.nom, reg.sex);
        fread(&reg, sizeof(t_pers), 1. fpEnt);
    }

    fclose(fpSal1);
    fclose(fpSal2);
    fclose(fpEnt);

    return 0;
}
