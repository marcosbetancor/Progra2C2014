#include "matrizcuadrada.h"


void cargamat (float matriz[][TAM])
{
    int fi,co;
    for(fi=0;fi<TAM;fi++)
        {for(co=0;co<TAM;co++)
            {printf("Ingrese valor de la posición [%d][%d]\n",fi,co);
            scanf("%f",&matriz[fi][co]);
            }
        }
}

void muestra (float diagprin,float supprin,float infprin,float diagsec,float supsec,float infsec)
{
    printf("Diagonal principal: %f\nSuperior Principal: %f\nInferior Principal: %f\nSuperior principal + Diagonal principal: %f\nInferior Principal con Diagonal: %f\n\nDiagonal secundaria: %f\nSuperior Secundaria:%f\nInferior Secundaria:%f\nSuperior Sec+Diagonal Sec:%f\nInferior Sec+Diag Sec:%f",diagprin,supprin,infprin,supprin+diagprin,infprin+diagprin,diagsec,supsec,infsec,supsec+diagsec,infsec+diagsec);
}

void calcula (float matriz[][TAM])
{
    int fi,co,diagonalprin=0,diagonalsec=0,inferiorprin=0,superiorprin=0,superiorsec=0,inferiorsec=0;
    for(fi=0;fi<TAM;fi++)
    {
        for(co=0;co<TAM;co++)
        {
            if(fi==co)
            diagonalprin+=matriz[fi][co];
            else
                if(fi<co)
                    superiorprin+=matriz[fi][co];
                    else
                        inferiorprin+=matriz[fi][co];
            if(fi+co==TAM-1)
                diagonalsec+=matriz[fi][co];
            else
                if(fi+co<=TAM-2)
                    superiorsec+=matriz[fi][co];
                else
                    inferiorsec+=matriz[fi][co];
        };
    };
muestra(diagonalprin,superiorprin,inferiorprin,diagonalsec,superiorsec,inferiorsec);
}
