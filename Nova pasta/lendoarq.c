#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct fila
{
    char pilha[200];
    int ini;
}fila;

int main ()
{
    char texto[200];
    char texto2[200];
    char palavra[50];
    int tam=0;
    int i=0;
    char c;

    fila *f;
    f = (fila*)malloc(sizeof(fila));



    FILE *fp;

    fp = fopen("texto", "r");
    if(fp == NULL)
    {
        printf("arquivo vazio");
        return 0;
    }
    else
    {
        while(fread(&texto, sizeof(char), 200, fp))
        {
            tam = strlen(texto);
            for(i=0;i<tam;i++)
            {
                c = texto[i];
                c = tolower(c);
                texto2 = c;
            }

            while(texto[i] != '\0')
            {
                int j = 0;
                while(j != '\n')
                {
                    c = texto2[j];
                    palavra[j] = c;
                }


            }
        }

    }


    return 0;
}
