#include <stdio.h>
#include <stdlib.h>
#define n 3
typedef struct
{
    char nome[30];
    int num_ouro, num_prata, num_bronze;

} Atleta;
void inserir(Atleta *);
void booble(Atleta *);
void imprimir(Atleta *vector);
int main(void)
{
    Atleta a_tleta[n];
    inserir(a_tleta);
    booble(a_tleta);
    imprimir(a_tleta);
}

void inserir(Atleta *a)
{
    for (int i = 0; i < n; i++)
    {
        printf("Insira o nome do atleta: ");
        scanf("%[^\n]s%*c", a[i].nome);
        printf("Insira a quantidade de medalhas de ouro: ");
        scanf("%d", &a[i].num_ouro);
        printf("Insira a quantidade de medalhas de prata: ");
        scanf("%d", &a[i].num_prata);
        printf("Insira a quantidade de medalhas de bronze: ");
        scanf("%d", &a[i].num_bronze);
        fflush(stdin);
    }
}
void booble(Atleta *vector)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (vector[j].num_ouro > vector[j + 1].num_ouro ||
                (vector[j].num_ouro == vector[j + 1].num_ouro && vector[j].num_prata > vector[j + 1].num_prata) ||
                (vector[j].num_ouro == vector[j + 1].num_ouro && vector[j].num_prata == vector[j + 1].num_prata && vector[j].num_bronze > vector[j + 1].num_bronze))
            { // junto com o algoritimo de troca;
                Atleta temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }
}
void imprimir(Atleta *vector)
{
    for (int i = 0; i < n; i++)
        printf("[%s]\n", vector[i].nome);
}
