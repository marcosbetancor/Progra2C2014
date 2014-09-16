#include<stdio.h>
#include"matrizcuadrada.h"

void main()
{
    float matriz [TAM][TAM]={{0}};
    int condseguir;
    while(condseguir!=0)
    {system("cls");
    fflush(stdin);
    cargamat(matriz);
    calcula (matriz);
    puts("\n\nIngrese 0(cero) para salir,1(uno) para continuar");
    do
    {scanf("%d",&condseguir);
    }while(condseguir!=0&&condseguir!=1);
    }
}
