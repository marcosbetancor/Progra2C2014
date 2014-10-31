#include <stdio.h>
#include <stdlib.h>

typedef struct
{   char marca[30];
    char nombre[30];
    char medida[6];
    char calidad[10];
    float metros;
    float precio;
    float oldprecio;
    int libertad;
    int mpaz;
    int rodriguez;
} t_ceramica;

int main()
{   FILE *archivo;
    t_ceramica reg;

if ((archivo = fopen("arch.txt", "at")) == NULL)
    {
     puts("error apertura");
    }

    printf("Ingrese marca");
    gets(reg.marca);
    fprintf(archivo, "%s\t%s\t%s\t%s\t%f\t%f\t%f\%d\%d\%d\n", reg.marca, reg.nombre, reg.medida, reg.calidad, reg.metros, reg.precio, reg.oldprecio, reg.libertad, reg.mpaz, reg.rodriguez);

}

