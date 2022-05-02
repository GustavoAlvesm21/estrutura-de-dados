// Pilha em uma lista ligada

#include <stdio.h> 
#include <stdlib.h> 

typedef struct pilha
{
    int valor; 
    struct pilha *prox; 
} pilha; 

typedef struct lista
{
    int topo; 
    struct pilha *ini;   
} lista; 

void menu(lista *l); 
lista *aloca_lista(); 
pilha *aloca_pilha(); 
void push(lista *l,int numero); 
int pop(lista *l); 

int main ()
{

    lista *l1; 

    l1 = aloca_lista(); 

    menu(l1); 

    return 0; 
}


void menu(lista *l)
{
    int numero; 
    int op; 
    int aux=0;

    do
    {
        printf("\n 1 -> Push");
        printf("\n 2 -> Pop");
        printf("\n 3 -> Stackpop");
        printf("\n 4 -> Sair"); 

        scanf("%d",&op); 

        switch (op)
        {
            case 1: 
                scanf("%d",&numero); 
                push(l,numero); 
                break; 

            case 2: 
                aux = pop(l);
                printf("%d foi removido", aux); 
                aux = 0; 
                break;

            case 3: 
                stackpop(l);  
                break;             

            case 4:
                break; 

            default:
                printf("opção invalida"); 
                break;     
        }   
    }
    while(op != 4); 
}

lista *aloca_lista()
{
   lista *novo; 

   novo = (lista*)malloc(sizeof(lista)); 
   novo->ini = NULL;
   novo->topo = 0; 

   return novo; 
}

pilha *aloca_pilha()
{
    pilha *novo; 

    novo = (pilha*)malloc(sizeof(pilha)); 
    novo->prox = NULL; 
    novo->valor = 0; 

    return novo;  
}

void push(lista *l,int numero)
{
    pilha *novo; 
    
    novo = aloca_pilha(); 
    novo->valor = numero; 

    if(l->ini == NULL)
    {
        l->ini = novo; 
    }
    else
    {
        novo->prox = l->ini; 
        l->ini = novo; 
    }

    l->topo++;    
}

int pop(lista *l)
{
    int valor; 

    if(l->topo == 0)
    {
        return 0; 
    }
    else
    {
        pilha *aux=NULL; 
        aux = l->ini; 
        valor = aux->valor; 
        l->ini = aux->prox; 
        free(aux); 
        l->topo--; 
        return valor; 
    }

}

void stackpop(lista *l)
{
    if(l->ini == NULL)
    {
        printf("lista vazia"); 
    }
    else 
    {
        printf("%d",l->ini); 
    }
}