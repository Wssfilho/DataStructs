#include "listaenc.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento no;
typedef struct elemento *Pno;
int main(void)
{
    int soma = 0;
    int i = 0;
    Pno inicio = NULL;
    Pno novo, aux;
    for (int i = 0; i < 20; i+=2)
    {
        novo = criarElemento(i);
        insereFim(&inicio, &novo);
    }
    aux = inicio;
    imprimir(inicio);
    while(aux != NULL)
    {
        i++;
        soma+=aux->valor;
        aux = aux->prox;
    }
    printf("\n\ntamanho: %d, soma: %d", i,soma);
}