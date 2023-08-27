#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nome[40];
} Indexs;

Indexs *alocar(int *);
void menu();
void inserir(Indexs *, const int);
void gravar(Indexs *, const int);
Indexs *realocar(Indexs *temp, int n);
void mostrarDoArquivo();
int main(void)
{
    int n;
    int op;
    Indexs *a;
    do
    {
        menu();
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            a = alocar(&n);
            inserir(a, n);
            gravar(a, n);
            break;
        case 2:
            mostrarDoArquivo();
            break;
        default:
            break;
        }
    } while (op != 0);
    free(a);
}
void mostrarDoArquivo()
{
    FILE *fp;
    int n;
    Indexs *temp;

    if ((fp = fopen("index.dat", "rb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(-1);
    }

    fread(&n, sizeof(int), 1, fp);
    temp = malloc(n * sizeof(Indexs));
    if (temp == NULL)
        exit(-1);

    fread(temp, sizeof(Indexs), n, fp);
    fclose(fp);

    for (int i = 0; i < n; i++)
    {
        printf("Nome: %s\n", temp[i].nome);
    }

    free(temp);
}

Indexs *realocar(Indexs *temp, int n)
{
    temp = realloc(temp, n * sizeof(Indexs));
    if (temp == NULL)
    {
        printf("error");
    }
    return temp;
}
void menu()
{
    printf("BEM VINDO AO SYSTEMA: \n");
    printf("1. Inserir\n");
    printf("2. mostrar\n");
    printf("0. Sair\n");
}

void gravar(Indexs *temp, const int n)
{
    FILE *fp;
    if ((fp = fopen("index.dat", "ab")) == NULL)
    {
        printf("Conflito de arquivo");
        exit(-1);
    }
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(temp, sizeof(Indexs), n, fp);
    fclose(fp);
}
void inserir(Indexs *temp, const int n)
{
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Insira o nome: ");
        gets(temp[i].nome);
        fflush(stdin);
    }
}
Indexs *alocar(int *n)
{
    printf("Insira o tamanho da turma: ");
    scanf("%d", n);
    Indexs *temp;
    temp = malloc(*n * sizeof(Indexs));
    if (temp == NULL)
        exit(-1);

    return temp;
}