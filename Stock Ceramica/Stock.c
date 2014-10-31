void cargaceram(FILE**baseceramica,t_ceramica varreg)
{
    int salida=1;
    while(salida!=0)
    {
        system("cls");
        printf("Ingrese modelo: ");
        scanf("%s",varreg.modelo);
        printf("Ingrese marca: ");
        scanf("%s",varreg.marca);
        printf("Ingrese medida: ");
        scanf("%s",&varreg.medida);
        printf("Ingrese calidad: ");
        scanf("%s",&varreg.calidad);
        printf("Ingrese cant. de metros por caja: ");
        scanf("%f",&varreg.metros);
        printf("Ingrese precio actual ");
        scanf("%f",&precio);
        printf("Ingrese precio viejo: ");
        scanf("%f",&varreg.oldprecio);
        printf("Ingrese stock en Libertad: ");
        scanf("%f",&varreg.stocksucur.libertad);
        printf("Ingrese stock en Marcos Paz: ");
        scanf("%f",&varreg.stocksucur.mpaz);
        printf("Ingrese stock en Rodriguez: ");
        scanf("%f",&varreg.stocksucur.rodriguez);

        fwrite(&varreg,sizeof(t_ceramica),1,*baseceramica);
        printf("\n\nPara seguir ingresando ceramica ingrese '1', para salir '0': ");
        scanf("%d",&salida);
    }
}


void modifceram(FILE**baseceramica,t_ceramica varreg)
{
    int opcion;
    char ncer[30];

    system("cls");
    printf("Ingrese ceramica a modificar: ");
    scanf("%s",&ncer);
    fseek(*baseceramica,sizeof(t_ceramica)*(nreg-1),0);
    printf("\n\nIngrese opcion para modificar:\n\t1- Modificar 1er parcial.\n\t2- Modificar 2do parcial.\n\nOPCION: ");
    scanf("%d",&opcion);
    if(opcion==1)
    {
        printf("Ingrese nota: ");
        fread(&varreg,sizeof(t_ceramica),1,*baseceramica);
        scanf("%d",&varreg.p1);
        fseek(*baseceramica,-sizeof(t_ceramica),1);
        varreg.prom=(varreg.p1 + varreg.p2)/2;
        fwrite(&varreg,sizeof(t_ceramica),1,*baseceramica);
        fseek(*baseceramica,0,1);}
    else
        {
            printf("Ingrese nota: ");
            fread(&varreg,sizeof(t_ceramica),1,*baseceramica);
            scanf("%d",&varreg.p2);
            fseek(*baseceramica,-sizeof(t_ceramica),1);
            varreg.prom=(varreg.p1 + varreg.p2)/2;
            fwrite(&varreg,sizeof(t_ceramica),1,*baseceramica);
            fseek(*baseceramica,0,1);}
        }

void muestraceram(FILE**baseceramica,t_ceramica varreg)
{
    int nreg=1;
    system("cls");
    fread(&varreg,sizeof(t_ceramica),1,*baseceramica);
    feof(*baseceramica);
    printf("\nApellido: %s\nNombre: %s\nFecha Nac: %d/%d/%d\n1er parcial: %d\n2do parcial: %d\nProm.Final: %f\nNumero de registro: %d\n\n",varreg.apellido,varreg.nombre,varreg.fnac.dd,varreg.fnac.mm,varreg.fnac.aa,varreg.p1,varreg.p2,varreg.prom,nreg);
    fread(&varreg,sizeof(t_ceramica),1,*baseceramica);
    while(!feof(*baseceramica))
    {
        printf("\nApellido: %s\nNombre: %s\nFecha Nac: %d/%d/%d\n1er parcial: %d\n2do parcial: %d\nProm.Final: %f\nNumero de registro: %d\n\n",varreg.apellido,varreg.nombre,varreg.fnac.dd,varreg.fnac.mm,varreg.fnac.aa,varreg.p1,varreg.p2,varreg.prom,nreg+1);
        fread(&varreg,sizeof(t_ceramica),1,*baseceramica);
        nreg++;
    }
}


void menuopc(FILE*baseceramica)
{
    t_ceramica varreg;
    int opcion;
    printf("Ingrese:\n\t 1-Crear base de datos.\n\t 2-Modificar base de datos.\n\t 3-Ver Base de datos\n\nOPCION: ");
    scanf("%d",&opcion);
    switch (opcion)
    {
        case 1 :
        baseceramica = fopen("arch.dat","w+b");
        if(!baseceramica)
            exit(1);
        else
            cargaceram(&baseceramica,varreg);
        break ;

        case 2 :
        baseceramica=fopen("arch.dat","r+b");
        if(!baseceramica)
            exit(1);
        else
            modifceram(&baseceramica,varreg);
        break ;

        case 3 :
        baseceramica=fopen("arch.dat","rb");
        if(!baseceramica)
            exit(1);
        else
            muestraceram(&baseceramica,varreg);
        break ;

        default :
        printf("\nOPCION INCORRECTA" );
        break ;
    }

    fclose(baseceramica);
}
