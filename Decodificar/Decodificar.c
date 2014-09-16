char *decodificar(char *s)
{
    char *orig = s,
         *dest = s;
    int n;

    while(*orig)
    {
    while(!esDigito(*orig) && *orig)
    {
        *dest = *orig;
        dest++;
        orig++;
    }

    if(*orig)
    {
      n = *orig - '0';
      orig++;
      invertirYDesplazar(orig, n, dest);
      orig + = n;
      dest + = n;
    }
    }
    *dest = '\0';
    return s;
}

void invertirYDesplazar(char *ori, int n, char *des)
{
    char *ini = ori;
        *fin = ori +n - 1;
         aux;

    while(ini < fin)
    {
        aux = *ini;
        *ini = *fin;
        *fin = aux;
        ini++;
        fin--;
    }

    while(n)
    {
        *des = *ori;
        des++;
        ori++;
        n--;
    }
}
