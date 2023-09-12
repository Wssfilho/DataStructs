#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 26

struct stack
{
    int top;
    char vagoes[STACKSIZE];
};

// verifica se pilha está vazia
int empty(struct stack *ps);
// remove e retorna item do topo da pilha;
int pop(struct stack *ps);
// insere intem x no topo da pilha
void push(struct stack *ps, int x);

int main(void)
{
    char operacoes[STACKSIZE];
    struct stack trem_esq, trem_dir;
    trem_dir.top = -1;
    trem_esq.top = -1;

    char vagoes[STACKSIZE];
    printf("Insira os vagoes: ");
    fflush(stdin);
    scanf("%s", vagoes);
    fflush(stdin);
    printf("Insira as operacoes: ");
    scanf("%s", operacoes);
    fflush(stdin);
    // printf("%s", vagoes);
    unsigned int i;
    int j = 0;
    for (i = 0; operacoes[i] != '\0'; i++)
    {
        if (operacoes[i] == 'E')
        {
            push(&trem_esq, vagoes[j]);
            j++;
        }
        else if (operacoes[i] == 'D')
        {
            push(&trem_dir, pop(&trem_esq));

        }
    }
    // for (int i = trem_dir.top; i >= 0; i--)
    // {
    //     printf("%c", trem_dir.vagoes[i]);
    // }
    printf("%s", trem_dir.vagoes);
    printf("\n");

    return 0;
}

int empty(struct stack *ps)
{
    if (ps->top == -1)
        return 1;
    return 0;
}

int pop(struct stack *ps)
{
    int aux;
    if (empty(ps))
    {
        printf("ERRO- PILHA VAZIA");
        exit(1);
    }

    aux = ps->vagoes[ps->top];
    ps->top--;
    return aux;
}

void push(struct stack *ps, int x)
{
    if (ps->top == STACKSIZE - 1)
    {
        printf("ERRO- PILHA CHEIA");
        exit(1);
    }

    ps->top++;
    ps->vagoes[ps->top] = x;
}