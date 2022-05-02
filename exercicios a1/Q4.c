// fila em uma lista ligada

#include <stdio.h> 
#include <stdlib.h>

typedef struct fila
{
    int valor;
    struct fila *prox; 
}fila;

typedef struct lista
{
    struct fila *ini; 
    int qtd; 
}lista;

void menu(lista *l); 
lista *aloca_lista(); 
fila *aloca_fila(); 
void push(lista *l,int numero); 
int remover(lista *l); 
void mostrar(lista *l); 

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
        printf("\n 3 -> Mostrar lista");
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
                mostrar(l); 
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
    novo->qtd = 0; 

    return novo; 
}

fila *aloca_fila()
{
    fila *novo; 

    novo = (fila*)malloc(sizeof(fila)); 
    novo->prox = NULL; 
    novo->valor = 0; 

    return novo; 
}

void incluir(lista *l, int numero)
{
    fila *novo,*aux; 
    novo = aloca_fila(); 
    novo->valor = numero; 

    if(l->ini == NULL)
    {
        l->ini = novo; 
    }
    else
    {
        aux = l->ini; 
        while(aux->prox != NULL)
        {
            aux = aux->prox; 
        }
        aux->prox = novo; 
    }
    l->qtd++; 
}

int remover(lista *l)
{
    int valor; 

    if(l->ini == NULL)
    {
        return 0; 
    }
    else
    {
        fila *aux; 
        aux = l->ini; 
        valor = aux->valor; 
        l->ini = aux->prox; 
        free(aux); 
        l->qtd--; 
        return valor; 
    }
}

void mostrar(lista *l)
{
    fila *aux; 
    
    if(l->ini == NULL)
    {
        printf("lista vazia"); 
    }
    else
    {
        aux = l->ini; 
        while(aux != NULL)
        {
            printf("%d ",aux->valor); 

            aux = aux->prox; 
        }
    }
}