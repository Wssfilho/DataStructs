#include <stdio.h>
#include <stdlib.h>
typedef struct No
{
    int dado;
    struct No *esq, *dir;

} No;
typedef No *pno;
pno criar_arvore(int x, pno esq, pno dir);
pno procurar_no(pno raiz, int x);
int numero_nos(pno raiz);
int altura(pno raiz);
int main(void)
{
}
pno criar_arvore(int dado, pno esq, pno dir)
{
    pno raiz = malloc(sizeof(No));
    raiz->esq = esq;
    raiz->dir = dir;
    raiz->dado = dado;
    return raiz;
}
pno procurar_no(pno raiz, int x)
{
    pno esq;
    if (raiz == NULL || raiz->dado == x)
        return raiz;
    esq = procurar_no(raiz->esq, x);
    if (esq != NULL)
        return esq;
    return procurar_no(raiz->dir, x);
}
int numero_nos(pno raiz)
{
    if (raiz == NULL)
        return 0;
    return numero_nos(raiz->esq) + numero_nos(raiz->dir) + 1;
}
int altura(pno raiz)
{
    int h_esq, h_dir;
    if (raiz == NULL)
        return 0;
    h_esq = altura(raiz->esq);
    h_dir = altura(raiz->dir);
    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}
