#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 4 // tamanho maximo do vector
typedef struct
{
    //
    int top;
    int s[STACKSIZE];
    /* data */
} Stack;

int empty(Stack *);
int pop(Stack *);
void push(Stack *, int);
void troca(Stack *);
int main(void)
{
    Stack vector;
    vector.top = -1;
    push(&vector, 1);
    push(&vector, 2);
    push(&vector, 3);
    push(&vector, 4);
    for (int i = 1; i <= vector.top; i++)
    {
        printf("[%d]\n", vector.s[i]);
    }
    printf("\nINDICE: %d", vector.s[0]);
}
void troca(Stack *vector)
{
    if (vector->top < 0)
    {
        printf("Nao pode ser manipulado");
        exit(1);
    }
    int first = pop(vector);
    int second = pop(vector);
    push(vector, first);
    push(vector, second);
    
}
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

    aux = ps->s[ps->top];
    ps->top--;
    ps->s[0] = ps->top;
    return aux;
}

void push(Stack *ps, int x)
{
    if (ps->top == STACKSIZE - 1)
    {
        printf("ERRO- PILHA CHEIA");
        exit(1);
    }

    ps->top++;
    ps->s[ps->top] = x;
    ps->s[0] = ps->top;
}