#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

typedef struct{
    int libertad;
    int mpaz;
    int rodriguez;
}t_sucur

 typedef struct{
    char modelo[30];
    char marca[30];
    char medida[6];
    char calidad[5];
    float metros;
    float precio;
    float oldprecio;
    t_sucur stocksucur;
    }t_ceramica;


void cargaceram(FILE**,t_ceramica);
void modifceram(FILE**,t_ceramica);
void muestraceram(FILE**,t_ceramica);
void menuopc(FILE*);

#endif // STOCK_H_INCLUDED
