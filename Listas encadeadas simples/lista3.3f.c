
#include <stdio.h>
#include <stdlib.h>
#define n 10

struct elemento
{
    int valor;
    struct elemento *prox;
};
typedef struct elemento no;
typedef struct elemento *Pno;

void imprimir(Pno inicio) // SO IMPRIME
{
    Pno atual;
    atual = inicio;
    while (atual != NULL)
    {
        printf("[%d] ", atual->valor);
        atual = atual->prox;
    }
}
int vazia(Pno inicio)
{
    if (inicio == NULL)
        return 1;
    else
        return 0;
}

Pno criarElemento(int valor) // char valor
{
    Pno novo;                       // CRIACAO DE ESTRUTURA DO TIPO PONTEIRO COM NOME NOVO
    novo = (Pno)malloc(sizeof(no)); // ALOCA (1) ESPACO NA MEMORIA E APONTA AUTOMATICAMENTE DO TAMANHO DA ESTRUTURA
    if (novo == NULL)
        exit(0);         // VERIFICA SE ALOCOU CERTO
    novo->valor = valor; // ENTAO ELE APONTA PARA O VALOR E COLOCA O VALOR
    novo->prox = NULL;   // ELE APONTA PARA O NULLO ESTANDO PREPARADO PARA ALOCAR OUTRO ESPACO
    return novo;         // RETORNA UM PONTEIRO PARA A NOVA ESTRUTUA QUE FOI ALOCADA
}

void insereFim(Pno *inicio, Pno *novo)
{
    Pno ultimo;

    if (vazia(*inicio))
        *inicio = *novo;
    else
    {
        // percorre ate encontrar ultimo
        ultimo = *inicio;
        while (ultimo->prox != NULL)
            ultimo = ultimo->prox;

        ultimo->prox = *novo; // INSERE NO FIM
    }
}
void separar(Pno *inicio, Pno *par, Pno *impar)
{
    Pno pecorrer = *inicio;
    while (pecorrer != NULL)
    {
        if ((pecorrer->valor % 2) == 0)
        {
            Pno novo = criarElemento(pecorrer->valor);
            insereFim(par, &novo);
        }
        else
        {
            Pno novo = criarElemento(pecorrer->valor);
            insereFim(impar, &novo);
        }
        pecorrer = pecorrer->prox;
    }
}
// Precisamos encotrar o anterior ao alvo
int main(void)
{
    Pno inicio = NULL, par = NULL, impar = NULL;
    Pno novo;
    novo = criarElemento(1);
    insereFim(&inicio, &novo);
    novo = criarElemento(2);
    insereFim(&inicio, &novo);
    novo = criarElemento(5);
    insereFim(&inicio, &novo);
    novo = criarElemento(7);
    insereFim(&inicio, &novo);
    novo = criarElemento(4);
    insereFim(&inicio, &novo);
    novo = criarElemento(3);
    insereFim(&inicio, &novo);
    novo = criarElemento(8);
    insereFim(&inicio, &novo);
    novo = criarElemento(6);
    insereFim(&inicio, &novo);
    separar(&inicio, &par, &impar);
    imprimir(inicio);
    printf("\n\n");
    imprimir(par);
    printf("\n\n");
    imprimir(impar);
}