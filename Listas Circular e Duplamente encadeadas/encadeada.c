#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor;
    struct elemento *prox;
    struct elemento *ant;
};
typedef struct elemento no;
typedef struct elemento *Pno;

int vazia(Pno inicio)
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}
Pno criarElemento(int valor)
{
    Pno novo;                       // CRIACAO DE ESTRUTURA DO TIPO PONTEIRO COM NOME NOVO
    novo = (Pno)malloc(sizeof(no)); // ALOCA (1) ESPACO NA MEMORIA E APONTA AUTOMATICAMENTE DO TAMANHO DA ESTRUTURA
    if (novo == NULL)
        exit(0);         // VERIFICA SE ALOCOU CERTO
    novo->valor = valor; // ENTAO ELE APONTA PARA O VALOR E COLOCA O VALOR
    novo->prox = NULL;   // ELE APONTA PARA O NULLO ESTANDO PREPARADO PARA ALOCAR OUTRO ESPACO
    novo->ant = NULL;
    return novo; // RETORNA UM PONTEIRO PARA A NOVA ESTRUTUA QUE FOI ALOCADA
}
void inserirIn(Pno *inicio, Pno *novo)
{
    if (vazia(*inicio))
    {
        *inicio = *novo;
    }
    else
    {
        (*novo)->prox = *inicio;
        (*inicio)->ant = *novo;
        *inicio = *novo;
    }
}
void inserefim(Pno *inicio, Pno *novo)
{
    if (vazia(*inicio))
    {
        *inicio = *novo;
    }
    else
    {
        Pno ultimo = *inicio;
        while(ultimo->prox != NULL)
        {
            ultimo = ultimo->prox;
        }
        ultimo->prox = *novo;
        (*novo)->ant = ultimo;
    }
}
void imprimir(Pno inicio)
{
    Pno aux = inicio;
    while(aux != NULL)
    {
        printf("Valor: %d", aux->valor);
        aux = aux->prox;
    }
}
int main(void)
{
    Pno inicio = NULL, novo;
    unsigned int num;
    printf("Insira um numero");
    scanf("%d", &num);
    novo = criarElemento(num);
    inserefim(&inicio, &novo);
    imprimir(inicio);
    
}
