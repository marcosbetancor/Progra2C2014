#include "StockCeramica.h"


int main()
{
    FILE* base;
    int salida = 1;

    backup(base);

    while(salida != 0)
    {
        menuopc(base);
        system("cls");
    }

    return 0;
}
