#include "listaenc.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento no;
typedef struct elemento *Pno;
int main(void)
{
    int i = 0;
    Pno inicio = NULL;
    Pno novo, aux;
    for (int i = 0; i < 4; i++)
    {
        novo = criarElemento(i);
        insereFim(&inicio, &novo);
    }
    aux = inicio;
    imprimir(inicio);
    while(aux != NULL)
    {
        i++;
        aux = aux->prox;
    }
    printf("%d", i);
}