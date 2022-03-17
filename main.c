#include <stdio.h> 
#include <stdlib.h>

typedef struct amostras
{
    char amostra[1000]; 
}amostras; 

int main () 
{
    int x;
    int abr;
    int fec;  
    scanf("%d",&x);
    amostras *vet_amostra;
    vet_amostra = (amostras*)malloc(sizeof(amostras*)*x); 

    for(int i=0;i<x;i++)
    {
        scanf("%s",&vet_amostra[i].amostra);

        //abr = verifica(vet_amostra);
        //fec = vericar2(vet_amostra);  

    }
}

int verifica(char *vet_amostra)
{

    int aux; 
    if(vet_amostra == '<')
    {
        push(); 
        //aux++; 
    }

    return aux; 
}

int verica2(char *vet_amostra)
{
    int aux2;
    if(vet_amostra == '>')
    {
        pop();
        //aux2; 
    }

    return aux2; 
}

/*criar uma nova struct para ser operada pelo pop e push, sendo que ao realizar o push 
vc modificar o valor de '>' para ponto. */