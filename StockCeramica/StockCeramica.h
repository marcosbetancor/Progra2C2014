#ifndef STOCKCERAMICA_H_INCLUDED
#define STOCKCERAMICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>
#define aMayus(x) ((x) >= 'a' && (x) <= 'z'? (x)-32: (x))
#define aMinus(x) ((x) >= 'A' && (x) <= 'Z'? (x)+32: (x))
#define esBlanco(x)((x) == ' ' || (x) == '\t'? 1 : 0)
#define RUTA "c:\\StockCeramica\\"


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

void nuevaCeram(FILE **, t_ceramica);
int obtenerDatos(FILE *,t_ceramica*);
char* normalizar(char* );
int Mezclar(FILE *, FILE **);
void Separar(FILE *, FILE **);
void Mezcla(FILE *);
void Mostrar(FILE *);
void modifPrecioxU(t_ceramica *,int );
void modifStock(t_ceramica *,int );
void busqueda(FILE *);
void modifPrecio(FILE *);
void menuopc(FILE *base);


#endif // STOCKCERAMICA_H_INCLUDED
