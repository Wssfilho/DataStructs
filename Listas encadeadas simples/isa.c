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
int vazia(Pno);
void imprimir(Pno inicio) // SO IMPRIME
{
    Pno atual;
    atual = inicio;
    while (atual != NULL)
    {
        printf("%d", atual->valor);
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

int removeFim(struct elemento **inicio) //agora, remove fim retorna um inteiro dps de ser removido
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
        a = alvo->valor; //quarta o inteiro

        if (alvo==*inicio)
        *inicio=NULL;

        anterior->prox = NULL;
        free(alvo);
    }
    return a; //retorna o inteiro
}

int main(void)
{
    Pno inicio = NULL;
    Pno novo, aux;
    int n, ent, a; //variaveis
    char entrada[40];

    do
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", entrada);
            if (strcmp(entrada, "BIPUSH") == 0) //se for BIPUSH cria o elemento e insere no fim da lista
            {
                scanf("%d", &ent);
                novo = criarElemento(ent);
                insereFim(&inicio, &novo);
                //printf("\n");
            }
            else if (strcmp(entrada, "ISUB") == 0) //se for isub ele pega os dois ultimos da lista, sibtrai e poe o resultado no topo (idem para IMUL E IADD)
            {
                a = removeFim(&inicio);
                a -= removeFim(&inicio);
                novo = criarElemento(a);
                insereFim(&inicio, &novo);
                //printf("\n");
            }
            else if (strcmp(entrada, "IMUL") == 0)
            {
                a = removeFim(&inicio);
                a *= removeFim(&inicio);
                aux = criarElemento(a);
                //printf("\n");
                insereFim(&inicio, &aux);
            }
            else if(strcmp(entrada, "IADD") == 0)
            {
                a = removeFim(&inicio);
                a += removeFim(&inicio);
                aux = criarElemento(a);
                insereFim(&inicio, &aux);
            }
        }
    } while (n != 0); //se n for 0 ele sai
    imprimir(inicio); //imprime o inicio
}