// Duas listas duplamente ligadas que retorna a concatenação das duas 

#include <stdio.h> 
#include <stdlib.h>

typedef struct registros
{
    int valor; 
    struct registros *prox;
}registros; 

typedef struct lista
{
    struct registros *ini; 
}lista; 

registros *inicia_registros(); 
lista *inicia_lista(); 

void incluir (lista *l1,int numero);
void incluir2 (lista *l2,int numero);  
void concatena (lista *l1, lista *l2); 
void mostrar_listas (lista *l); 
void menu (lista *l1, lista *l2); 

int main ()
{

    lista *l1; 
    lista *l2;  

    l1 = inicia_lista(); 
    l2 = inicia_lista();  

    menu(l1,l2); 

    return 0; 
}

registros *inicia_registros()
{
    registros *novo; 
    novo = (registros*)malloc(sizeof(registros)); 

    novo->prox = NULL; 
    novo->valor = 0; 

    return novo; 
}

lista *inicia_lista()
{
    lista *novo; 
    novo = (lista*)malloc(sizeof(lista)); 

    novo->ini = NULL; 

    return novo; 
}

void incluir(lista *l1,int numero)
{
    registros *novo; 
    novo = inicia_registros(); 

    novo->valor = numero; 
    
    if(l1->ini == NULL)
    {
        l1->ini = novo; 
    }
    else
    {
        novo->prox = l1->ini; 
        l1->ini = novo; 
    }
}

void incluir2(lista *l2,int numero)
{
    registros *novo; 
    novo = inicia_registros(); 

    novo->valor = numero; 
    
    if(l2->ini == NULL)
    {
        l2->ini = novo; 
    }
    else
    {
        novo->prox = l2->ini; 
        l2->ini = novo; 
    }
}

void mostrar_listas (lista *l)
{
    if(l->ini == NULL)
    {
        printf("lista vazia"); 
    }
    else
    {
        registros *aux; 
        aux = l->ini; 

        while(aux != NULL)
        {
            printf("%d, ",aux->valor); 
            aux = aux->prox; 
        }
    }
}

void concatena (lista *l1, lista *l2)
{
    registros *aux; 
    aux = l1->ini; 
    
    while(aux->prox != NULL)
    {
        aux = aux->prox; 
    }

    aux->prox = l2->ini;  
}

void menu(lista *l1, lista *l2)
{
    int numero; 
    int op;  

    do
    {
        printf("\n 1 - Incluir na lista 1");
        printf("\n 2 - Incluir na lista 2");
        printf("\n 3 - Mostrar a lista 1");
        printf("\n 4 - Mostrar a lista 2");
        printf("\n 5 - Concatenar listas");
        printf("\n 6 - Mostrar listas concatenadas");
        printf("\n 7 - Sair\n"); 
        
        scanf("%d",&op);

        switch(op)
        {
            case 1:
                scanf("%d",&numero); 
                incluir(l1,numero);
                break; 
            
            case 2:
                scanf("%d",&numero); 
                incluir2(l2,numero); 
                break; 
            
            case 3:
                mostrar_listas(l1);
                break; 
            
            case 4:
                mostrar_listas(l2); 
                break; 
            
            case 5:
                concatena(l1,l2); 
                break; 
            
            case 6:
                mostrar_listas(l1); 
                break; 
            
            case 7:
                break;

            default:
                break;  
        }
    }while(op != 7);
}