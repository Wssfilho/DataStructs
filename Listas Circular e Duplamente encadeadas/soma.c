#include <stdio.h>
#include <stdlib.h>
struct elemento
{
    int valor;
    struct elemento *proximo;
    struct elemento *anterior;
};
typedef struct elemento *Pno;
typedef struct elemento No;
void inserirFim(Pno *, Pno *);
int vazia(Pno);
Pno criarElemento(int);
void Soma(Pno, Pno, int);

int main(void)
{
    int numero, elem;
    Pno lista1 = NULL, lista2 = NULL, novo;

    scanf("%d", &numero);
    while (numero >= 0 && numero <= 1000)
    {

        for (int i = 0; i < numero; i++)
        {
            scanf("%d", &elem);
            novo = criarElemento(elem);
            inserirFim(&lista1, &novo);
        }

        for (int i = 0; i < numero; i++)
        {
            scanf("%d", &elem);
            novo = criarElemento(elem);
            inserirFim(&lista2, &novo);
        }

        Soma(lista1, lista2, numero);

        lista1 = NULL;
        lista2 = NULL;

        scanf("%d", &numero);
    }
    return 0;
}
int vazia(Pno inicio)
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}
Pno criarElemento(int valor)
{
    Pno novo;
    novo = (Pno)malloc(sizeof(No));

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}
void inserirFim(Pno *inicio, Pno *novo)
{
    Pno ultimo;

    if (vazia(*inicio))
        *inicio = *novo;
    else
    {
        ultimo = *inicio;
        while (ultimo->proximo != NULL)
            ultimo = ultimo->proximo;
        ultimo->proximo = *novo;
        (*novo)->anterior = ultimo;
    }
}
void Soma(Pno inicio1, Pno ultimo2, int valor)
{
    Pno aux1 = inicio1;
    Pno aux2 = ultimo2;

    while (aux2->proximo != NULL)
    {
        aux2 = aux2->proximo;
    }
    printf("\n");
    for (int i = 0; i < valor; i++)
    {
        int soma = aux1->valor + aux2->valor;
        printf("%d ", soma);

        if (aux1->proximo != NULL)
        {
            aux1 = aux1->proximo;
        }

        if (aux2->anterior != NULL)
        {
            aux2 = aux2->anterior;
        }
    }
    printf("\n");
}