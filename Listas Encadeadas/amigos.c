#include <stdio.h>
#include <stdlib.h>
struct elemento
{
    int valor;
    struct elemento *prox;
};
typedef struct elemento no;
typedef struct elemento *Pno;

Pno criarLista(int);
int Eliminacao(Pno, int);
void inserir(const int casos);
int main(void)
{
    
    int casos;
    scanf("%d", &casos);
    inserir(casos);
    
    return 0;
}
void inserir(const int casos)
{
    Pno lista;
    int amigos, lim, *vencedor; 
    vencedor = malloc(casos * sizeof(int));
    if (vencedor == NULL)
        exit(-1);
    for (int i = 0; i < casos; i++)
    {
        scanf("%d", &amigos);
        scanf("%d", &lim);
        lista = criarLista(amigos);
        vencedor[i] = Eliminacao(lista, lim);
    }
    printf("Vecedores: \n");
    for (int j = 0; j < casos; j++)
    {
        printf("%d\n", vencedor[j]);
    }
    free(vencedor);
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

Pno criarLista(int valor)
{
    Pno inicio = criarElemento(1);
    Pno aux = inicio;
    for (int i = 2; i <= valor; i++)
    {
        aux->prox = criarElemento(i);
        aux = aux->prox;
    }
    aux->prox = inicio;
    return inicio;
}

int Eliminacao(Pno inicio, int valor)
{
    Pno atual = inicio;
    Pno b = NULL;
    int i = 1;
    while (atual->prox != atual)
    {
        if (i == valor)
        {
            if (b)
            {
                b->prox = atual->prox;
                free(atual);
                atual = b->prox;
            }
            else
            {
                no *aux = atual->prox;
                while (aux->prox != inicio)
                {
                    aux = aux->prox;
                }
                aux->prox = atual->prox;
                free(atual);
                inicio = aux->prox;
                atual = inicio;
            }
            i = 1;
        }
        else
        {
            i++;
            b = atual;
            atual = atual->prox;
        }
    }
    int vencedor = atual->valor;
    free(atual);
    inicio = NULL;
    return vencedor;
}