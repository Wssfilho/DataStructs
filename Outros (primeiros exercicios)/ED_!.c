#include <stdio.h>
#include <stdlib.h>
/* ENUNCIADO
Crie e ordene (em ordem crescente) um vetor de atletas. Para cada atleta, você deve guardar as seguintes informações: nome, numero de medalhas de ouro, numero de medalhas de prata e numero de medalhas de bronze. A ordenação deve respeitar a seguinte regra: menor número de medalhas de ouro, em caso de empate, menor numero de medalhas de prata, se ainda houver empate, menor número de medalhas de bronze. Se ainda houver empate, escolher qualquer ordem. 

Você deverá usar um vetor de estruturas para essa tarefa. E deverá utilizar o algoritmo de bubble sort. Claro que terá que fazer adaptações a ele. 
Obs: não é necessário usar alocação dinâmica

A estrutura é a seguinte:
struct Atleta {
    char nome[100];
    int n_ouro, n_prata, n_bronze;
};
*/

typedef struct //declaração de uma estrutura que tem os campos nome e numero de medalhas;
{
    char nome[30];
    int num_ouro, num_prata, num_bronze;

} Atleta;
void inserir(Atleta *, const int); //funcao para pegar os dados do usuario
void booble(Atleta *, const int); //funcao para ordenar de acordo com o enunciado
void imprimir(Atleta *vector, const int); //funcao para mostrar na tela o nome depois de ordenado
int main(void)
{
    int n; //para controlar a quantidade de usuario
    printf("Insira o numero de jogadores: ");
    scanf("%d", &n);
    Atleta a_tleta[n]; //variavle do tipo struct Atleta
    inserir(a_tleta, n); //chamada de funcoes
    booble(a_tleta, n);
    imprimir(a_tleta, n);
}
void inserir(Atleta *a, const int n) //funcao do tipo void, inserir, que recebe um ponteiro vetor do tipo estrutura atleta
{
    for (int i = 0; i < n; i++) //laco para receber os dados
    {
        fflush(stdin);
        printf("Insira o nome do atleta: ");
        scanf("%[^\n]s%*c", a[i].nome);
        printf("Insira a quantidade de medalhas de ouro: ");
        scanf("%d", &a[i].num_ouro);
        printf("Insira a quantidade de medalhas de prata: "); //recebendo os dados
        scanf("%d", &a[i].num_prata);
        printf("Insira a quantidade de medalhas de bronze: ");
        scanf("%d", &a[i].num_bronze);
        fflush(stdin);
    }
}
void booble(Atleta *vector, const int n) //funcao do tipo void, booble, de ordenação que tambem recebe um poteiro para estrutura
{
    int i, j; //variaveis
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++) //algoritimo de ordenação
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
void imprimir(Atleta *vector, const int n) //funcao do tipo void, imprimir, que recebe um ponteiro à estrutura e o que faz é imprimir na tela
{
    for (int i = 0; i < n; i++)
        printf("[%s]\n", vector[i].nome);
}