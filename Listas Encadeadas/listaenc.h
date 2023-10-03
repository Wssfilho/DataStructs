#include "listaenc.c"
void imprimir(Pno inicio);
int vazia(Pno inicio);
Pno criarElemento(int valor);
void inserirIn(Pno *inicio, Pno *novo);
void removerIn(Pno *inicio);
Pno busca(Pno *inicio, int x);
void insereFim(Pno *inicio, Pno *novo);
void removeAlvo(Pno *inicio, Pno *alvo);
void removeFim(struct elemento **inicio);
void insereOrdenado(Pno *inicio, Pno *novo);
