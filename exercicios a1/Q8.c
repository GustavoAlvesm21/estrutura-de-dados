// Lista duplamente ligada que mostra os primos, soma dos pares e o menor e maior numero.

#include <stdio.h> 
#include <stdlib.h>

typedef struct registros
{
    int valor; 
    struct registros *prox; 
    struct registros *ant; 
}registros; 

typedef struct lista
{
    struct registros *ini; 
    struct registros *fim;
    int alterna;
    int qtd;   
}lista; 

registros *inicia_registros(); 
lista *inicia_lista(); 
void inserir(lista *l,int numero,int alt);
void mostrar(lista *l);  
void primos(lista *l); 
void pares(lista *l); 
void menor_maior(lista *l); 

int main ()
{

    int op; 
    int numero; 
    int alt; 
    lista *l1; 

    l1 = inicia_lista(); 

    do
    {
        printf("\n1 - Inserir no inicio");
        printf("\n2 - Inserir no fim");
        printf("\n3 - Mostrar");
        printf("\n4 - Contar primos");
        printf("\n5 - Somar os pares");
        printf("\n6 - Mostrar menor e maior");
        printf("\n10 - Sair");

        scanf("%d",&op); 

        switch(op)
        {
            case 1:
                alt = 0; 
                scanf("%d",&numero); 
                inserir(l1,numero,alt); 
                break; 
            
            case 2:
                alt = 1; 
                scanf("%d",&numero); 
                inserir(l1,numero,alt); 
                break;

            case 3: 
                mostrar(l1);
                break;  
            
            case 4:
                primos(l1); 
                break; 

            case 5: 
                pares(l1); 
                break; 

            case 6: 
                menor_maior(l1); 
                break; 

            case 10:
                break; 
            
            default:
                break; 
        }
    }while(op != 10); 

    return 0; 
}

registros *inicia_registros()
{
    registros *novo; 
    novo = (registros*)malloc(sizeof(lista)); 

    novo->prox = NULL; 
    novo->ant = NULL; 
    novo->valor = 0; 

    return novo; 
}

lista *inicia_lista()
{
    lista *novo; 
    novo = (lista*)malloc(sizeof(lista)); 

    novo->ini = NULL; 
    novo->fim = NULL;
    novo->alterna = 0;  

    return novo; 
}

void inserir (lista *l,int numero,int alt)
{

    registros *novo; 
    novo = inicia_registros(); 

    novo->valor = numero; 
    l->alterna = alt; 

    if(l->ini == NULL)
    {
        l->ini = novo;     //1 -> fim / 0 -> inicio
        l->fim = novo; 
        l->qtd++; 
    }
    else
    {
        if(l->alterna == 1)
        {  
            l->fim->prox = novo; 
            novo->ant = l->fim;
            l->fim = novo;  
            l->qtd++; 
        }
        else if(l->alterna == 0)
        {
            l->ini->ant = novo; 
            novo->prox = l->ini; 
            l->ini = novo;
            l->qtd++;  
        }
    }
}

void mostrar(lista *l)
{
    registros *aux; 

    if(l->ini == NULL)
    {
        printf("lista vazia");  
    }
    else
    {
        aux = l->ini; 
        while(aux != NULL)
        {
            printf("%d ", aux->valor); 
            aux = aux->prox; 
        }
    }

}

void primos(lista *l)
{
    registros *aux;
    int primos = 0;  
    aux = l->ini; 

    if(l->ini == NULL)
    {
        printf("lista vazia"); 
    }
    else
    {
        while(aux != NULL)
        {

            if(aux->valor % 2 != 0 && aux->valor % 3 != 0)
            {
                primos++; 
            }
            else if(aux->valor == 2 || aux->valor == 3)
            {
                primos++; 
            }
            
            aux = aux->prox; 
        }

        printf("Tem %d numero(s) primos",primos); 
    }
}

void pares(lista *l)
{
    registros *aux;
    int soma_pares = 0; 
    
    if(l->ini == NULL)
    {
        printf("lista vazia"); 
    }
    else
    {
        aux = l->ini; 
        while(aux != NULL)
        {
            if(aux->valor % 2 == 0)
            {
                soma_pares = soma_pares + aux->valor; 
            }
            aux = aux->prox; 
        }

        printf("soma do(s) pares -> %d",soma_pares); 
    }
}

void menor_maior(lista *l)
{

    int maior = 0; 
    int menor = 1000; 

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
            if(aux->valor > maior)
            {
                maior = aux->valor; 
            }
            else if(aux->valor < menor)
            {
                menor = aux->valor; 
            }

            aux = aux->prox; 
        }

        printf("\n Maior -> %d \n Menor -> %d",maior,menor); 
    }
}