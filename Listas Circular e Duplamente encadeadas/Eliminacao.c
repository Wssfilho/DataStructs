#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um elemento
struct elemento
{
    int valor;             // Valor do elemento
    struct elemento *prox; // Ponteiro para o próximo elemento
};
typedef struct elemento no;   // Definindo 'no' como um sinônimo para 'struct elemento'
typedef struct elemento *Pno; // Definindo 'Pno' como um sinônimo para o ponteiro para 'struct elemento'

// Protótipos das funções
Pno criarLista(int);
int retirar(Pno, int);
void menu(const int casos);

// Função principal
int main(void)
{
    int casos;
    scanf("%d", &casos); // Lê a quantidade de casos
    menu(casos);      // Chama a função 'inserir' passando a quantidade de casos

    return 0;
}

// Função que insere elementos na lista
void menu(const int casos)
{
    Pno lista;
    int amigos, lim, *vencedor;
    vencedor = malloc(casos * sizeof(int)); // Aloca memória para o vetor 'vencedor'
    if (vencedor == NULL)                   // Verifica se a alocação foi bem sucedida
        exit(-1);
    for (int i = 0; i < casos; i++)
    {
        scanf("%d", &amigos);                 // Lê a quantidade de amigos
        scanf("%d", &lim);                    // Lê o limite
        lista = criarLista(amigos);           // Cria a lista com a quantidade de amigos
        vencedor[i] = retirar(lista, lim); // Chama a função 'Eliminacao' e armazena o resultado no vetor 'vencedor'
    }
    printf("Vecedores: \n");
    for (int j = 0; j < casos; j++)
    {
        printf("%d\n", vencedor[j]); // Imprime os vencedores
    }
    free(vencedor); // Libera a memória alocada para o vetor 'vencedor'
}

// Função que cria um novo elemento
Pno criarElemento(int valor)
{
    Pno novo;
    novo = (Pno)malloc(sizeof(no));
    if (novo == NULL) // Verifica se a alocação foi bem sucedida
        exit(0);
    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

// Função que cria uma lista circular com uma quantidade específica de elementos
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

// Função que realiza a eliminação dos elementos da lista
int retirar(Pno inicio, int valor)
{
    Pno atual = inicio; // Ponteiro para o elemento atual
    Pno aux1 = NULL;       // Ponteiro para o elemento anterior
    int i = 1;          // Contador

    // Enquanto houver mais de um elemento na lista
    while (atual->prox != atual)
    {
        // Se o contador é igual ao valor passado como parâmetro
        if (i == valor)
        {
            // Se 'b' não é nulo (ou seja, se não estamos no primeiro elemento)
            if (aux1)
            {
                // Faz o elemento anterior apontar para o próximo elemento
                aux1->prox = atual->prox;
                // Libera a memória do elemento atual
                free(atual);
                // Atualiza o ponteiro para o elemento atual
                atual = aux1->prox;
            }
            else
            {
                // Se estamos no primeiro elemento
                no *aux = atual->prox;
                // Encontra o último elemento da lista
                while (aux->prox != inicio)
                {
                    aux = aux->prox;
                }
                // Faz o último elemento apontar para o segundo elemento
                aux->prox = atual->prox;
                // Libera a memória do primeiro elemento
                free(atual);
                // Atualiza o ponteiro para o início da lista e para o elemento atual
                inicio = aux->prox;
                atual = inicio;
            }
            // Reinicia o contador
            i = 1;
        }
        else
        {
            // Incrementa o contador e move os ponteiros para o próximo elemento
            i++;
            aux1 = atual;
            atual = atual->prox;
        }
    }
    // Armazena o valor do último elemento restante
    int vencedor = atual->valor;
    // Libera a memória do último elemento e zera o ponteiro para o início da lista
    free(atual);
    inicio = NULL;

    return vencedor; // Retorna o valor do último elemento restante
}
