#include "StockCeramica.h"

void nuevaCeram(FILE **base, t_ceramica varreg)
{
    int salida=1, guardar;

    while(salida!=0)
    {
        fflush(stdin);
        system("cls");
        printf("Ingrese marca: ");
        gets(varreg.marca);
        normalizar(varreg.marca);
        printf("Ingrese nombre: ");
        gets(varreg.nombre);
        normalizar(varreg.nombre);
        printf("Ingrese medida: ");
        gets(varreg.medida);
        printf("Ingrese calidad: ");
        gets(varreg.calidad);
        printf("Ingrese Mt/Caja: ");
        scanf("%f", &varreg.metros);
        printf("Ingrese precio x M2: ");
        scanf("%f", &varreg.precio);
        printf("Ingrese precio anterior: ");
        scanf("%f", &varreg.oldprecio);
        printf("Ingrese Stock en Libertad: ");
        scanf("%d", &varreg.libertad);
        printf("Ingrese Stock en Marcos Paz: ");
        scanf("%d", &varreg.mpaz);
        printf("Ingrese Stock en Rodriguez: ");
        scanf("%d", &varreg.rodriguez);

        puts("\n\n\t\t1- Guardar // 2- Eliminar");
        scanf("%d", &guardar);

        if(guardar == 1)
        {
            fprintf(*base,"%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%d\t%d\t%d\n", varreg.marca, varreg.nombre, varreg.medida, varreg.calidad, varreg.metros, varreg.precio, varreg.oldprecio, varreg.libertad, varreg.mpaz, varreg.rodriguez);
        }
        printf("\n\nPara seguir ingresando ceramica ingrese '1', para salir '0': ");
        scanf("%d",&salida);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
// Carga en una variable de estructura una cadena desdeun archivo de texto luego la prsea y la guarda.

int obtenerDatos(FILE *base, t_ceramica *arrayreg)
{
    int i = 0;
    char cad[200];
    char *aux;

    while(fgets(cad,sizeof(cad),base))
    {
        aux=strchr(cad,'\n');//BUSCA EN LA CADENA EL CARACTER DE SALTO DE LINEA
        *aux='\0';

        aux=strrchr(cad,'\t');//BUSCA DE ATRAS PARA ADELANTE DENTRO DE LA CADENA LINEA EL PRIMER \t
        sscanf(aux+1,"%d",&arrayreg[i].rodriguez);
        *aux='\0';

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%d",&arrayreg[i].mpaz);
        *aux='\0';

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%d",&arrayreg[i].libertad);
        *aux='\0';//SEGUIS DE A UNO SEPARANDO HASTA QUE LLEGAS AL ULTIMO

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%f",&arrayreg[i].oldprecio);
        *aux='\0';

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%f",&arrayreg[i].precio);
        *aux='\0';

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%f",&arrayreg[i].metros);
        *aux='\0';

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%s",arrayreg[i].calidad);
        *aux='\0';

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%s", arrayreg[i].medida);
        *aux='\0';

        aux=strrchr(cad,'\t');
        sscanf(aux+1,"%[^\n]s",arrayreg[i].nombre);
        *aux='\0';

        strcpy(arrayreg[i].marca, cad);

        i++;
    }

    return (i);
}
///////////////////////////////////////////////////////////////////////////////////////////////////
// Normalizar cadena significa a cada primer letra de cada palabra convertirla en mayuscula y las demas en minuscula.

char* normalizar(char* cad)
{
    char *orig = cad,
         *dest = cad;

    while(*orig)
    {
        while(esBlanco(*orig))
            orig++;
        if(*orig)
        {
            *dest = aMayus(*orig);
            dest++;
            orig++;

            while(!esBlanco(*orig)&&*orig)
            {
                *dest = aMinus(*orig);
                dest++;
                orig++;
            }
            if(esBlanco(*orig))
            {
                *dest=' ';
                dest++;
                orig++;
            }

        }
    }
    if(dest > cad && *(dest-1) == ' ')
        dest--;
    *dest = '\0';
    return cad;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// Mezcla los ficheros auxiliares:
int Mezclar(FILE *fich, FILE **aux)
{
   char ultima[128], linea[2][128], anterior[2][128];
   int entrada;
   int tramos = 0;

   // Lee la primera línea de cada fichero auxiliar:
   fgets(linea[0], 128, aux[0]);
   fgets(linea[1], 128, aux[1]);
   // Valores iniciales;
   strcpy(ultima, "");
   strcpy(anterior[0], "");
   strcpy(anterior[1], "");
   // Bucle, mientras no se acabe ninguno de los ficheros auxiliares (quedan tramos por mezclar):
   while(!feof(aux[0]) && !feof(aux[1])) {
      // Selecciona la línea que se añadirá:
      if(strcmp(linea[0], linea[1]) <= 0) entrada = 0; else entrada = 1;
      // Almacena el valor como el último añadido:
      strcpy(anterior[entrada], linea[entrada]);
      // Añade la línea al fichero:
      fputs(linea[entrada], fich);
      // Lee la siguiente línea del fichero auxiliar:
      fgets(linea[entrada], 128, aux[entrada]);
      // Verificar fin de tramo, si es así copiar el resto del otro tramo:
      if(strcmp(anterior[entrada], linea[entrada]) > 0) {
         if(!entrada) entrada = 1; else entrada = 0;
         tramos++;
         // Copia lo que queda del tramo actual al fichero de salida:
         do {
            strcpy(anterior[entrada], linea[entrada]);
            fputs(linea[entrada], fich);
            fgets(linea[entrada], 128, aux[entrada]);
         } while(!feof(aux[entrada]) && strcmp(anterior[entrada], linea[entrada]) <= 0);
      }
   }

   // Añadir tramos que queden sin mezclar:
   if(!feof(aux[0])) tramos++;
   while(!feof(aux[0])) {
      fputs(linea[0], fich);
      fgets(linea[0], 128, aux[0]);
   }
   if(!feof(aux[1])) tramos++;
   while(!feof(aux[1])) {
      fputs(linea[1], fich);
      fgets(linea[1], 128, aux[1]);
   }
   return(tramos == 1);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
// Separa los tramos ordenados alternando entre los ficheros auxiliares:
void Separar(FILE *fich, FILE **aux)
{
   char linea[128], anterior[2][128];
   int salida = 0;

   // Volores iniciales para los últimos valores
   // almacenados en los ficheros auxiliares
   strcpy(anterior[0], "");
   strcpy(anterior[1], "");
   // Captura la primero línea:
   fgets(linea, 128, fich);
   while(!feof(fich)) {
      // Decide a qué fichero de salida corresponde la línea leída:
      if(salida == 0 && strcmp(linea, anterior[0]) < 0) salida = 1;
      else if(salida == 1 && strcmp(linea, anterior[1]) < 0) salida = 0;
      // Almacena la línea actual como la última añadida:
      strcpy(anterior[salida], linea);
      // Añade la línea al fichero auxiliar:
      fputs(linea, aux[salida]);
      // Lee la siguiente línea:
      fgets(linea, 128, fich);
   }
}

////////////////////////////////////////////////////////////////////////

void Mezcla(FILE *fich)
{
   int ordenado;
   FILE *aux[2];

   // Bucle que se repite hasta que el fichero esté ordenado:
   do {
      // Crea los dos ficheros auxiliares para separar los tramos:
      aux[0] = fopen(RUTA"aux1.txt", "w+");
      aux[1] = fopen(RUTA"aux2.txt", "w+");
      rewind(fich);
      Separar(fich, aux);
      rewind(aux[0]);
      rewind(aux[1]);
      rewind(fich);
      ordenado = Mezclar(fich, aux);
      fclose(aux[0]);
      fclose(aux[1]);
   } while(!ordenado);
   // Elimina los ficheros auxiliares:
   remove(RUTA"aux1.txt");
   remove(RUTA"aux2.txt");
}

///////////////////////////////////////////////////////////////////////////////

void Mostrar(FILE *base)
{
     int i = 0,
          cant;

    t_ceramica arrayreg[1000];

     system("cls");
     printf("\n\tCod - \tNombre\t\t\t\tMed.\tCal.\tMarca\t\tM2\tPrecio\tPrec.Viejo\tLib    Mpaz    Rodrig\n");
     printf("\t-------------------------------------------------------------------------------------------------------------------------------\n");

     cant = obtenerDatos(base, arrayreg);

    for(i = 0; i < cant; i++)
    {
        printf("\t  %d - \t%-30s\t%s\t%s\t%-12s\t%-5.2f\t$%-5.2f\t$%-5.2f\t\t%-4d\t%-4d\t %-4d\n", i, arrayreg[i].nombre,arrayreg[i].medida, arrayreg[i].calidad, arrayreg[i].marca, arrayreg[i].metros, arrayreg[i].precio, arrayreg[i].oldprecio, arrayreg[i].libertad, arrayreg[i].mpaz, arrayreg[i].rodriguez);
        printf("\t-------------------------------------------------------------------------------------------------------------------------------\n");
    }

    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Recibe array de registros y modifica el precio x m2

void modifPrecioxU(t_ceramica *arrayreg,int i)
{
    float precio;

    printf("Ingrese precio nuevo: ");
    scanf("%f", &precio);

    arrayreg[i].oldprecio = arrayreg[i].precio;
    arrayreg[i].precio = precio;

    system("cls");
    printf("Precio modificado\n\n");
    printf("\nCod - \tNombre\t\tMed.\tCal.\tMarca\t\t\tM2\tPrecio\tPrec.Viejo\tLib    Mpaz  Rodrig\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf(" %d - \t%-10s\t%s\t%s\t%-8s\t\t%.2f\t$%.2f\t$%.2f\t\t%-8d%-7d%d\n", i, arrayreg[i].nombre,arrayreg[i].medida, arrayreg[i].calidad, arrayreg[i].marca, arrayreg[i].metros, arrayreg[i].precio, arrayreg[i].oldprecio, arrayreg[i].libertad, arrayreg[i].mpaz, arrayreg[i].rodriguez);
    printf("--------------------------------------------------------------------------------------------------------------------\n\n");
    system("pause");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
// Recibe array de registros y modifica los stocks

void modifStock(t_ceramica *arrayreg,int i)
{
    int opcion,
        cant;

    printf("Ingrese accion: 1 - Sumar \n\t\t2 - Restar\n\t\t\n\n");
    scanf("%d",&opcion);

    system("cls");

    switch(opcion)
    {
    case 1:
       printf("Libertad: %d\t SUMAR: ", arrayreg[i].libertad);
       scanf("%d",&cant);
       arrayreg[i].libertad+= cant;
       printf("\nMarcos Paz: %d\t SUMAR: ", arrayreg[i].mpaz);
       scanf("%d",&cant);
       arrayreg[i].mpaz+= cant;
       printf("\nRodriguez: %d\t SUMAR: ", arrayreg[i].rodriguez);
       scanf("%d",&cant);
       arrayreg[i].rodriguez+= cant;
       printf("--------------------------------------------------------------------------------------------------------------------\n");
       printf("--------------------------------------------------------------------------------------------------------------------\n");
       printf("\nCod - \tNombre\t\tMed.\tCal.\tMarca\t\t\tM2\tPrecio\tPrec.Viejo\tLib    Mpaz  Rodrig\n");
       printf("----------------------------------------------------------------------------------------------------------------\n");
       printf(" %d - \t%-10s\t%s\t%s\t%-8s\t\t%.2f\t$%.2f\t$%.2f\t\t%-8d%-7d%d\n", i, arrayreg[i].nombre,arrayreg[i].medida, arrayreg[i].calidad, arrayreg[i].marca, arrayreg[i].metros, arrayreg[i].precio, arrayreg[i].oldprecio, arrayreg[i].libertad, arrayreg[i].mpaz, arrayreg[i].rodriguez);
       printf("----------------------------------------------------------------------------------------------------------------\n\n");
       break;

    case 2:
       printf("Libertad: %d\t RESTAR: ", arrayreg[i].libertad);
       scanf("%d",&cant);
       arrayreg[i].libertad-= cant;
       printf("\nMarcos Paz: %d\t RESTAR: ", arrayreg[i].mpaz);
       scanf("%d",&cant);
       arrayreg[i].mpaz-= cant;
       printf("\nRodriguez: %d\t RESTAR: ", arrayreg[i].rodriguez);
       scanf("%d",&cant);
       arrayreg[i].rodriguez-= cant;
       printf("----------------------------------------------------------------------------------------------------------------\n");
       printf("----------------------------------------------------------------------------------------------------------------\n");
       printf("Cod - \tNombre\t\tMed.\tCal.\tMarca\t\t\tM2\tPrecio\tPrec.Viejo\tLib    Mpaz  Rodrig\n");
       printf("--------------------------------------------------------------------------------------------------------------------\n\n");
       printf(" %d - \t%-10s\t%s\t%s\t%-8s\t\t%.2f\t$%.2f\t$%.2f\t\t%-8d%-7d%d\n", i, arrayreg[i].nombre,arrayreg[i].medida, arrayreg[i].calidad, arrayreg[i].marca, arrayreg[i].metros, arrayreg[i].precio, arrayreg[i].oldprecio, arrayreg[i].libertad, arrayreg[i].mpaz, arrayreg[i].rodriguez);
       printf("--------------------------------------------------------------------------------------------------------------------\n\n");
       break;
        }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Busca una ceramica específica

void busqueda(FILE *base)
{   t_ceramica arrayreg[1000];

    int i = 0,
        opcion,
        cantreg,
        cont = 0;

    char auxcad[30];

    Mezcla(base);
    system("cls");
    printf("Nombre: ");
    fflush(stdin);
    gets(auxcad);
    normalizar(auxcad);

    system("cls");
    printf("\n\tCod - \tNombre\t\tMed.\tCal.\tMarca\t\t\tM2\tPrecio\tPrec.Viejo\tLib    Mpaz  Rodrig\n");
    printf("\t----------------------------------------------------------------------------------------------------------------\n");

    cantreg = obtenerDatos(base, arrayreg);

    for(i = 0; i < cantreg; i++)
    {
        if((strcmpi(auxcad, arrayreg[i].nombre))== 0)
        {
            printf("\t  %d - \t%-10s\t%s\t%s\t%-8s\t\t%.2f\t$%.2f\t$%.2f\t\t%-8d%-7d%d\n", i, arrayreg[i].nombre,arrayreg[i].medida, arrayreg[i].calidad, arrayreg[i].marca, arrayreg[i].metros, arrayreg[i].precio, arrayreg[i].oldprecio, arrayreg[i].libertad, arrayreg[i].mpaz, arrayreg[i].rodriguez);
            printf("\t----------------------------------------------------------------------------------------------------------------\n");
            cont ++;
        }
    }

    if(cont != 0)
    {
        printf("\n\nCOD. a modificar: ");
        scanf("%d",&i);
        system("cls");
        printf("Ingrese opcion: 1 - Modificar Stock\n\t\t2 - Modificar Precio x m2\n\t\t3 - Eliminar\n\t\t4 - Salir\n\nOPCION: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
        system("cls");
        modifStock(arrayreg, i);
        break;

        case 2:
        system("cls");
        modifPrecioxU(arrayreg, i);
        break;

        case 3:
        system("cls");
        strcpy(arrayreg[i].nombre, "remove" );
        break;

        default:
        system("cls");
        menuopc(base);
        break;
        }
    }
    else
    {
        system("cls");
        puts("NO HAY COINCIDENCIA\n\n");
    }

    fclose(base);

    if(ferror(base))
            fputs("Error cerrando archivo base.txt", stderr );

    base = fopen(RUTA"base.txt","wt");

    if(base == NULL)
    {
        fputs("Error abriendo archivo",stderr);
        exit(1);}

    for(i = 0 ; i < cantreg ; i++)
    {
        if(strcmp(arrayreg[i].nombre, "remove") != 0)
        {
            fprintf(base,"%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%d\t%d\t%d\n", arrayreg[i].marca, arrayreg[i].nombre, arrayreg[i].medida, arrayreg[i].calidad, arrayreg[i].metros, arrayreg[i].precio, arrayreg[i].oldprecio, arrayreg[i].libertad, arrayreg[i].mpaz, arrayreg[i].rodriguez);
        }
    }

    fclose(base);

    if(ferror(base))
        fputs("Error cerrando archivo base.txt", stderr );

    system("pause");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Modifica precios por marca globalmente y producto a producto segun se elija

void modifPrecio(FILE *base)
{
    t_ceramica arrayreg[1000];

    int i = 0,
        cant = 0,
        cont = 0;

    char marca[30];

    float aumporc;

    cant = obtenerDatos(base, arrayreg);

    fclose(base);

    system("cls");

    printf("Ingrese marca: ");
    fflush(stdin);
    gets(marca);
    printf("Ingrese aumento porcentual: ");
    scanf("%f",&aumporc);

    system("cls");

    for(i = 0; i < cant; i++)
    {
        if((strcmpi(marca, arrayreg[i].marca)) == 0)
        {
            arrayreg[i].oldprecio = arrayreg[i].precio;
            arrayreg[i].precio+= (aumporc * arrayreg[i].precio)/100;
            cont++;
        }
    }


    if(cont > 0)
    {
        base = fopen(RUTA"base.txt","r+t");
        if(base == NULL)
            {fputs("Error abriendo archivo",stderr);
            exit(1);}
         else
         {


        for(i = 0 ;i < cant; i++)
        {
            fprintf(base,"%s\t%s\t%s\t%s\t%.2f\t%.2f\t%.2f\t%d\t%d\t%d\n", arrayreg[i].marca, arrayreg[i].nombre, arrayreg[i].medida, arrayreg[i].calidad, arrayreg[i].metros, arrayreg[i].precio, arrayreg[i].oldprecio, arrayreg[i].libertad, arrayreg[i].mpaz, arrayreg[i].rodriguez);


        }
        printf("Precios de %s aumentados un %.2f%%\n\n",marca,aumporc);
        system("pause");
        }
    }
    else
    {
        puts("NO EXISTE MARCA\n\n");
        system("pause");
    }

    fclose(base);

    if(ferror(base))
            fputs("Error cerrando archivo base.txt", stderr );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Crea Backup
void backup(FILE *base)
{
FILE *fin,
     *fout;
char c, x;

mkdir(RUTA"\\BACKUP\\");

if (((fin = fopen(RUTA"base.txt", "rt")) == NULL) || ((fout = fopen(RUTA"\\BACKUP\\backup.txt" , "wt")) == NULL))
{
    if (fout!= NULL)
        fclose(fout);
        if (fin!= NULL)
            fclose (fin) ;
            printf ("Error en la apertura de ficheros de salida\n");
}

c = fgetc(fin);
while (c != EOF)
{
    x = fputc (c, fout);
    if (x!=c)
        printf ("Error de escritura");
    c = fgetc(fin);
}
fclose (fin);
fclose (fout);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Menu de opciones

void menuopc(FILE *base)
{
    t_ceramica varreg;
    int opcion;


    system("cls");
    printf("Ingrese:\n\t 1- Nueva Ceramica\n\t 2- Ver LISTADO\n\t 3- Busqueda (Ver || Modif.Stock || Modif.Precio)\n\t 4- Modif. Precio por marca\n\t 5- Crear BACKUP\n\t 6- Salir\n\nOPCION: ");
    scanf("%d",&opcion);
    system("cls");

    switch (opcion)
    {
        case 1 :
        mkdir(RUTA);
        base = fopen(RUTA"base.txt","at");
        if(base == NULL)
            {fputs("Error abriendo archivo",stderr);
            exit(1);}

        nuevaCeram(&base, varreg);
        fclose(base);
        if(ferror(base))
            fputs("Error cerrando archivo base.txt", stderr );

        base = fopen(RUTA"base.txt", "r+t");
        if(base == NULL)
            {fputs("Error abriendo archivo",stderr);
            exit(1);}

        Mezcla(base);
        fclose(base);
        if(ferror(base))
         {
             fputs("Error cerrando archivo base.txt", stderr );
            system("pause");
         }
        break;

        case 2 :
        base = fopen(RUTA"base.txt","rt");
        if(base == NULL)
        {
            fputs("Error abriendo archivo",stderr);
            exit(1);
        }

        Mostrar(base);
        fclose(base);
        if(ferror(base))
            fputs("Error cerrando archivo base.txt", stderr );
        system("pause");

        break ;

        case 3:
        base = fopen(RUTA"base.txt", "rt");
        if(base == NULL)
            {fputs("Error abriendo archivo",stderr);
            exit(1);}
        busqueda(base);
        break;

        case 4:
        base = fopen(RUTA"base.txt", "rt");
        if(base == NULL)
            {fputs("Error abriendo archivo",stderr);
            exit(1);}
        modifPrecio(base);
        break;

        case 5:
        backup(base);
        system("cls");
        puts("BACKUP EXITOSO!!");
        system("pause");
        menuopc(base);
        break;

        case 6:
        system("cls");
        printf("Programa hecho por MARCOS BETANCOR\n\n\n\n");
        system("pause");
        exit(1);
        break;

        default:
        puts("Opcion incorrecta");
        system("pause");
        system("cls");
        menuopc(base);
        break;
    }
}

