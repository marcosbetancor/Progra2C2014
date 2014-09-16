#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

typedef
{
    long dni;
    char ape[36];
    char nom[41]
    char sex;
} t_pers;

#define ARCH_DATOS "datos"
#define SALIDA1 "datos.txt"
#define SALIDA2 "datos2.txt"
#define con_msj 1

//#define t_pers t_info;

int abrirArchivo(FILE   **, const char *, const char *, int )

#endif // ARCHIVOS_H_INCLUDED
