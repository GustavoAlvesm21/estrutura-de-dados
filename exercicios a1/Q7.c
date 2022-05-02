// Questao de inserir alternadamente entre o inicio e o final e depois proucurar um numero e dizer se ta mais perto do inicio ou do final. 

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
void inserir(lista *l,int numero);
void mostrar(lista *l); 
void search(lista *l,int alvo); 
void distancia(lista *l,int dist); 

int main ()
{

    int op; 
    int numero; 
    lista *l1; 

    l1 = inicia_lista(); 

    do
    {
        printf("\n1 - Inserir");
        printf("\n2 - Mostrar");
        printf("\n3 - Proucura numero");
        printf("\n4 - Sair");

        scanf("%d",&op); 

        switch(op)
        {
            case 1:
                scanf("%d",&numero); 
                inserir(l1,numero); 
                break; 
            
            case 2:
                mostrar(l1); 
                break; 

            case 3: 
                scanf("%d",&numero); 
                search(l1,numero); 
                break; 
            
            case 4:
                break; 
            
            default:
                break; 
        }
    }while(op != 4); 

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

void inserir (lista *l,int numero)
{

    registros *novo; 
    novo = inicia_registros(); 

    novo->valor = numero; 

    if(l->ini == NULL)
    {
        l->ini = novo;     //1 -> fim / 0 -> inicio
        l->fim = novo;
        l->alterna++;  
        l->qtd++; 
    }
    else
    {
        if(l->alterna == 1)
        {  
            l->fim->prox = novo; 
            novo->ant = l->fim;
            l->fim = novo;  
            l->alterna--;
            l->qtd++; 
        }
        else if(l->alterna == 0)
        {
            l->ini->ant = novo; 
            novo->prox = l->ini; 
            l->ini = novo;
            l->alterna++;
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

void search(lista *l,int alvo)
{
    int cont; 
    registros *aux;

    aux = l->ini; 
    while(aux->valor != alvo)
    {
        aux = aux->prox; 
        cont++; 
    }
    distancia(l,cont);
}

void distancia(lista *l,int dist)
{
    float aux; 
    aux = l->qtd / 2; 

    if(dist < aux)
    {
        printf("O numero esta mais perto do inicio"); 
    }
    else if(dist > aux)
    {
        printf("O numero esta mais perto do fim"); 
    }
}