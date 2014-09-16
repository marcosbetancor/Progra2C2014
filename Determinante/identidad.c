#include "identidad.h"

int esIdentidad(int m[][TAM])
{
    int fi,
        co;

    for(fi=0; fi<TAM; fi++)
    {
        if(m[fi][fi]!=1)
            return 0;
        for(co = fi + 1 ; co <TAM; co++)
                if(m[fi][co]!=0 || m[co][fi]!=0)
                    return 0;
    }
    return 1;
}

int esIdentidad2(int m[][TAM])
{
    int fi,
        co;

    for(fi=0; fi<TAM; fi++)
    {
        if(m[fi][fi]!=1)
            return 0;

        for(co = TAM-fi ; co <TAM; co++)
                if(m[fi][co]!=0 || m[co][fi]!=0)
                    return 0;
    }
    return 1;
}
