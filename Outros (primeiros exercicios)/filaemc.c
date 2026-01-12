#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 4 // tamanho maximo do vector
typedef struct
{

    int top;
    int items[STACKSIZE];
    /* data */
    
} Stack;

int empty(Stack *);
int pop(Stack *);
void push(Stack *, int);
void troca(Stack *);
int main(void)
{
    char c;
    int op;
    Stack vector;
    vector.top = 0;
   for(int i = 0; i <= vector.top; i++)
   {
        scanf("%c", &c);
        scanf("%d", &op);
        if(c == 'E')
        {
            push(&vector, op);
        }
        else if(c == 'D')
        {
            pop(&vector);
        }
        else if(c == '-')
        {
            break;
        }
        printf("%d ", vector.items[i]);
   }
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

    aux = ps->items[ps->top];
    ps->top--;
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
    ps->items[ps->top] = x;
}