#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 4
typedef struct
{
    int item;
    struct stack *prox;
    struct stack *ant;
}No;
typedef struct filha
{
    No *top;
    No *ult;
}Filha;
void remove(Filha *inicio);
// typedef struct stack no;
// typedef struct stack *Pno;

// int remove(Pno *inicio)
// {
//     if((*inicio)->top == -1)
//     {
//         return 0;
//     }
//     else
//     {
        
//     }
// }