#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        printf("[%d]", atual->valor);
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

Pno criarElemento(int valor)
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

int main(void)
{
    Pno inicio = NULL;
    Pno novo, aux, aux2;
    int n, ent, a, b;
    char entrada[40];
    aux = inicio;
    do
    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            scanf("%s", entrada);
            if (strcmp(entrada, "BIPUSH") == 0)
            {
                scanf("%d", &ent);
                novo = criarElemento(ent);
                insereFim(&inicio, &novo);
                imprimir(inicio);
            }
            else if (strcmp(entrada, "ISUB") == 0)
            {
                aux = inicio;
                while (!(aux == NULL))
                {

                    a = aux->prox->prox->valor;
                    printf("%d\n", a);
                    removeFim(&inicio);
                    a-=aux->prox->valor;
                    printf("%d", a);
                    removeFim(&inicio);
                    aux2 = criarElemento(a);
                    insereFim(&inicio, &aux2);
                    imprimir(inicio);
                    break;
                }
            }
            else if (strcmp(entrada, "IMUL") == 0)
            {
                aux = inicio;
                while (!(aux == NULL))
                {

                    a = aux->prox->prox->valor;
                    printf("%d\n", a);
                    removeFim(&inicio);
                    a*=aux->prox->valor;
                    printf("%d", a);
                    removeFim(&inicio);
                    aux2 = criarElemento(a);
                    insereFim(&inicio, &aux2);
                    imprimir(inicio);
                    break;

                }
            }
        }
        imprimir(inicio);

    } while (n != 0);
}