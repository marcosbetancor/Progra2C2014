typedef struct
{
    int di;
        me;
        an;
}t_fecha;

void aFecha(const char *s, t_fecha *fec)
{
    char aux[4];
        *aux2;
    static char meses[] = {"ENE|FEB|MAR|ABR|MAY|JUN|JUL|AGO|SEP|OCT|NOV|DIC"};
    sscanf(s,"%d%*c%3s%*c%d",&fec->di,aux,&fec->an);
    aux2= strstr(meses, aux);
    fec->me= (int)(aux2-meses)/4+1;
}
