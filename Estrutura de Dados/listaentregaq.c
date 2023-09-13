#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 26

typedef struct
{
    int top;
    char vagoes[STACKSIZE];
} Stack;

int empty(Stack *ps);
int pop(Stack *ps);
void push(Stack *ps, int x);
char *alocar(int n);

int main(void)
{
    int n;
    char operacoes[STACKSIZE];
    Stack trem_esq, trem_dir;
    trem_dir.top = -1;
    trem_esq.top = -1;

    printf("Insira o tamanho do vagao: ");
    scanf("%d", &n);
    fflush(stdin);

    char *vagoes = alocar(n);

    printf("Insira os vagoes: ");
    fgets(vagoes, n, stdin);
    fflush(stdin);

    printf("Insira as operacoes: ");
    fgets(operacoes, STACKSIZE, stdin);
    fflush(stdin);

    int i, j = 0;

    for (i = 0; operacoes[i] != '\0'; i++)
    {
        if (operacoes[i] == 'E')
        {
            if (j < n)
            {
                push(&trem_esq, vagoes[j]);
                j++;
            }
            else
            {
                printf("Não há mais vagões para mover.\n");
                break;
            }
        }
        else if (operacoes[i] == 'D')
        {
            if (!empty(&trem_esq))
            {
                push(&trem_dir, pop(&trem_esq));
            }
            else
            {
                printf("Não há mais vagões para mover.\n");
                break;
            }
        }
    }

    printf("\n");

    for (int i = 0; i <= trem_dir.top; i++)
    {
        printf("%c ", trem_dir.vagoes[i]);
    }

    free(vagoes);

    return 0;
}

char *alocar(int n)
{
    char *temp;
    temp = malloc(n * sizeof(char));

    if (temp == NULL)
        exit(-1);

    return temp;
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

    aux = ps->vagoes[ps->top];
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
    ps->vagoes[ps->top] = x;
}
