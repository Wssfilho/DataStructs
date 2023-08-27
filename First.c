#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
//algorithm of ordenation
//algoritimo de ordenacao
void inserir(int n, int *);
int *alocacao(int *n);
void booble(int[], int n);
void troca(int *, int *);  
void imprimir(int *, const int);
int main(void)
{
    int n;
    int *vector = alocacao(&n);
    inserir(n, vector);
    booble(vector, n);
    imprimir(vector, n);
    free(vector);
    return 0;
}
void imprimir(int *vector, const int n)
{
    for(int i = 0; i < n; i++)
        printf("[%d] - value: %d\n", i, vector[i]);
}
void inserir(int n, int *vector)
{
    for(int i = 0; i < n; i++)
    {
        printf("Insira o numero na posicao %d", i + 1);
        scanf("%d", &vector[i]);
    }
}
int *alocacao(int *n)
{
    int k;
    printf("Insira o tamanho do vector: ");
    scanf("%d", &k);
    int *vector = malloc(k * sizeof(int));
    if(vector == NULL)
        return 0;
    *n = k;
    return vector;
}
void booble(int vector[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                troca(&vector[j], &vector[j + 1]);
            }
        }
    }
}
void troca(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}