//Questao 1069 do bee, que é a da mineração de dima

#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

typedef struct pilhas
{
    char pilha[1000]; 
    int ini; 
}pilhas; 

int pop(pilhas *p); 
int push(pilhas *p);
int empty(pilhas *p);

int main ()
{
    int n;
    int tam=0; 
    int aux=0; 
    char amostra[1000]; 
    scanf("%d",&n); 
    pilhas *p; 
    p = (pilhas*)malloc(sizeof(pilhas)); 
    p->ini =-1; 

    while(n != 0)
    {
        scanf("%s",amostra); 
        tam = strlen(amostra); 
        for(int i=0;i<tam;i++)
        {
            if(amostra[i] == '<')
            {
                push(p); 
            }
            else if(amostra[i] == '>')
            {
                if(pop(p))
                {
                    aux++; 
                } 
            }

        }
        printf("\n%d\n",aux); 
        memset(p->pilha,0,1000);
        p->ini = -1; 
        aux = 0; 
        n--;  
    }

    return 0; 
}

int push(pilhas *p)
{
    p->ini++; 
    p->pilha[p->ini] = '<'; 

    return 1; 
}

int pop(pilhas *p)
{ 
    if(empty(p))
    {
        return 0; 
    } 
    else 
    {
        p->pilha[p->ini] = '.'; 
        p->ini--;
        return 1; 
    } 
}

int empty(pilhas *p)
{
    if(p->ini == -1)
    {
        return 1; 
    }
    else
    {
        return 0;
    } 
}
