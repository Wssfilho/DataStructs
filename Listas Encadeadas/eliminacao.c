/* Implementação base de uma lista simplesmente encadeada circular
com números inteiros. Usem essa implementação para possíveis adaptações*/
#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int valor;
    struct elemento *prox;
};

typedef struct elemento No;
typedef struct elemento *Pno;

/* verifica se é vazia. Se sim, retorna 1; se não, retorna 0. */
int vazia(Pno inicio)
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}

/* Percorre e imprimir lista. Recebe o início da lista*/
void mostrarLista(Pno inicio)
{
    Pno atual;
    atual = inicio;
    if (!vazia(inicio))
    {
        do
        {
            printf("%d ", atual->valor);
            atual = atual->prox;
        } while (atual != inicio);
    }
}

// recebe dados(valor) e retorna um elemento com este dado
Pno criaElemento(int valor)
{
    Pno novo;
    novo = (Pno)malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    return novo;
}

/*Percebam que aqui, nós iremos/podemos mudar os conteúdos dos ponteiros inicio e novo.
 Por isso precisamos passa-los como ponteiros.
 Portanto temos ponteiros de ponteiro: struct elemento ** inicio ou Pno *inicio */
void insereInicio(Pno *inicio, Pno *novo)
{
    Pno ultimo = *inicio;

    if (vazia(*inicio))
    {
        *inicio = *novo;
        (*inicio)->prox = *inicio; // mantem propriedade circular
    }
    else
    {
        (*novo)->prox = *inicio;

        // encontrar o ultimo elemento
        while (ultimo->prox != *inicio)
            ultimo = ultimo->prox;

        *inicio = *novo;
        ultimo->prox = *inicio; // mantem a propriedade circular
    }
}
int removeFim(struct elemento **inicio)
{
    int a;
    Pno alvo = *inicio;
    Pno anterior = *inicio;

    if (!vazia(*inicio))
    {
        while (alvo->prox != NULL)
        {
            anterior = alvo;
            alvo = alvo->prox;
        }
        a = alvo->valor;

        if (alvo == *inicio)
            *inicio = NULL;

        anterior->prox = NULL;
        free(alvo);
    }
    return a;
}
int main(void)
{
    Pno inicio1 = NULL;
    Pno novo;
    unsigned int i, n, a, b = 0, teste, k;
    scanf("%d", &a);
    do
    {
        scanf("%d %d", &n, &b);
        for (i = n; i != 0; i--)
        {
            novo = criaElemento(i);
            insereInicio(&inicio1, &novo);
        }
        mostrarLista(inicio1);
        while (inicio1->prox != inicio1 && b < n)
        {

            
            inicio1 = inicio1->prox;
            teste = inicio1->valor;
            inicio1 = inicio1->prox;
            b++;
            k = removeFim(&inicio1);
        }
        printf("[%d], valor de k: [%d]", teste, k);

        a--;
    } while (a != 0);

    return 0;
}
