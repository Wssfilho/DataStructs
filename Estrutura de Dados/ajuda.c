#include <stdio.h>
#include <stdlib.h>

#define MAX 26

typedef struct
{
    char vagoes[MAX];
    int top;
} Stack;
int empty(Stack *ps)
{
    if (ps->top == -1)
        return 1;
    return 0;
}

int pop(Stack *ps)
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

void push(Stack *ps, int x)
{
    if (ps->top == MAX - 1)
    {
        printf("ERRO- PILHA CHEIA");
        exit(1);
    }

    ps->top++;
    ps->vagoes[ps->top] = x;
}
int main()
{
    int j = 0;
    Stack esquerdo, direito;
    esquerdo.top = direito.top = -1;

    char vagoes[] =    "ABCDEFGH";
    char operacoes[] = "EEEDEEDDDEDEE";

    for (int i = 0; operacoes[i] != '\0'; i++)
    {

        if (operacoes[i] == 'E')
        {
            push(&esquerdo, vagoes[j]);
            j++;
        }
        else if (operacoes[i] == 'D')
        {
            push(&direito, pop(&esquerdo));
        }
    }

    printf("Estado final dos vagoes do lado direito: ");
    while (direito.top != -1)
    {
        printf("%c ", pop(&direito));
    }

    return 0;
}
