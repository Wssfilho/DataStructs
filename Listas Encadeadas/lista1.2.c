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
        printf("[%c]\n ", atual->valor);
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

Pno criarElemento(char valor) // char valor
{
    Pno novo;                       // CRIACAO DE ESTRUTURA DO TIPO PONTEIRO COM NOME NOVO
    novo = (Pno)malloc(sizeof(no)); // ALOCA (1) ESPACO NA MEMORIA E APONTA AUTOMATICAMENTE DO TAMANHO DA ESTRUTURA
    if (novo == NULL)
        exit(0);         // VERIFICA SE ALOCOU CERTO
    novo->valor = valor; // ENTAO ELE APONTA PARA O VALOR E COLOCA O VALOR
    novo->prox = NULL;   // ELE APONTA PARA O NULLO ESTANDO PREPARADO PARA ALOCAR OUTRO ESPACO
    return novo;         // RETORNA UM PONTEIRO PARA A NOVA ESTRUTUA QUE FOI ALOCADA
}
void inserirIn(Pno *inicio, Pno *novo)
{
    if (vazia(*inicio))
    {
        *inicio = *novo; // VERIFICA SE ESTA VAZIO, SE SIM ELE APONTA PARA UM NOVO
    }
    else
    {
        (*novo)->prox = *inicio; // SE NAO ESTA VAZIO ELE CRIA UM ESPACO E JA APONTA PARA O INICIO
        *inicio = *novo;
    }
}
void removerIn(Pno *inicio)
{
    if (!vazia(*inicio)) //SE NAO TIVER VAZIO O ALVO APONTA PARA O INCIO, O INCICIO GUARDA O ALVO, ENTAO ELE LIBERA A POSICAO
    {
        Pno alvo = *inicio;
        *inicio = alvo->prox;
        free(alvo);
    }
}
Pno busca(Pno *inicio, int x)
{
    Pno alvo = *inicio;  // O ALVO APONTA PARA O INICIO
    while (alvo != NULL) // ENQUANTO O ALVO NAO FOR NULL, OU SEJA, ENQUANTO NAO ACABAR A LISTA!
    {
        if (alvo->valor == x) // COMPARA SE CADA VALOR DE CADA ESTRUTURA EH IGUAL AO VALOR INDICADO
            return alvo;      // SE ACHAR JA RETORNA
        alvo = alvo->prox;    // SE NAO ACHAR ELE CONTINUA ANDANDO
    }
    return alvo; // SE NAO TIVER O ELEMENTO ELE RETORNA A ESTRUTURA
    //(PODEMOS FAZER UMA FUNCAO QUE MOSTRA SE ALVO == 1 POR EXEMPLO E MOSTRAR UMA MENSAGEM QUE O ELEMENTO NAO ESTA NA LISTA)
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
// Precisamos encotrar o anterior ao alvo
void removeAlvo(Pno *inicio, Pno *alvo)
{
    Pno anterior = *inicio;

    if (!vazia(*inicio))
    {
        if (*inicio == *alvo)
        { // se alvo é elemento do início
            *inicio = (*inicio)->prox;
            free(*alvo);
        }
        else
        {
            while (anterior->prox != *alvo)
                anterior = anterior->prox;

            anterior->prox = (*alvo)->prox;
            free(*alvo);
        }
    }
}

void removeFim(struct elemento **inicio)
{
    Pno alvo = *inicio;
    Pno anterior = *inicio;

    if (!vazia(*inicio))
    {
        while (alvo->prox != NULL)
        {
            anterior = alvo;
            alvo = alvo->prox;
        }
        anterior->prox = NULL;
        free(alvo);
    }
}
// void concatenar
void insereOrdenado(Pno *inicio, Pno *novo)
{
    Pno anterior;

    if (vazia(*inicio))
        *inicio = *novo;
    else
    {
        // anterior será último elemento menor que novo.
        anterior = *inicio;
        // se prox do anterior ainda é menor que novo, então anterior será o prox;
        while ((anterior->prox != NULL) &&
               (anterior->prox->valor < (*novo)->valor)) // para strings usar função strcmp
            anterior = anterior->prox;

        (*novo)->prox = anterior->prox;
        anterior->prox = *novo;
    }
}

int main(void)
{
    Pno inicio = NULL;
    Pno novo, aux;
    // demonstracao de pilha
    // novo = criarElemento('A');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('Z');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('X');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('B');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('C');
    // insereFim(&inicio, &novo);
    // imprimir(inicio);
    // novo = criarElemento('E');
    // insereFim(&inicio, &novo);
    // printf("\n");
    // imprimir(inicio);
    // removeFim(&inicio);
    // printf("\n");
    // imprimir(inicio);

    // //demonstracao de fila
    // novo = criarElemento('A');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('Z');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('X');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('B');
    // insereFim(&inicio, &novo);
    // novo = criarElemento('C');
    // insereFim(&inicio, &novo);
    // printf("\n");
    // imprimir(inicio);
    // removerIn(&inicio);
    // printf("\n");
    // imprimir(inicio);
    // demosntracao de ordenacao
    // novo = criarElemento(1);
    // insereOrdenado(&inicio, &novo);
    // novo = criarElemento(2);
    // insereOrdenado(&inicio, &novo);
    // novo = criarElemento(5);
    // insereOrdenado(&inicio, &novo);
    // novo = criarElemento(3);
    // insereOrdenado(&inicio, &novo);
    // imprimir(inicio);
}