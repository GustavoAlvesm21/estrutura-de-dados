//Questão 1110 do bee , que é a das cartas

#include <stdio.h>
#include <stdlib.h>

int pop(int x, int *bar);
int pop2(int x, int *bar); 
void push(int x,int re,int *bar);

int prim=0;
int ult=-1; 

int main ()
{
    int x,dis,re,tam; 
    scanf("%d",&x); 
    if(x<2 || x>50)
    {
        return 0; 
    }
    int bar[x]; 
    for(int i=0;i<x;i++)
    {
        bar[i] = i + 1; 
    }
    tam = x; 
    
    printf("Discartadas: ");
    while(tam>=2)
    {
        dis = pop(x,bar); 
        tam--; 
        printf("%d,",dis); 
        re = pop2(x,bar);
        tam--; 
        push(x,re,bar);
        tam++;   
    }

    printf("\nSobrou: %d",bar[ult]); 

    return 0; 
}

pop(int x,int *bar)
{
    int aux; 
    if(prim > x-1)
    {
        prim = 0; 
        aux = bar[prim]; 
        prim++; 

        return aux;
    }
    else
    {
        aux = bar[prim]; 
        prim++; 

        return aux; 
    }
}

int pop2(int x, int *bar)
{
    int aux2; 
    if(prim > x-1)
    {
        prim = 0; 
        aux2 = bar[prim]; 
        prim++; 

        return aux2;
    }
    else
    {
        aux2 = bar[prim]; 
        prim++; 

        return aux2; 
    }
}

void push(int x,int re,int *bar)
{
    ult++; 
    bar[ult] = re; 
}