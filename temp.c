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
void removerDoArquivo(char *nome);
int main(void)
{
    char nome[40];
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
        case 3:
            printf("Insira o nome para remover: ");
            scanf("%*c%[^\n]s%*c", nome);
            removerDoArquivo(nome);
            break;
        default:
            break;
        }
    } while (op != 0);
    free(a);
}
void removerDoArquivo(char *nome)
{
    FILE *fp, *fpTemp;
    Indexs temp;
    int encontrou = 0;

    if ((fp = fopen("index.dat", "rb")) == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(-1);
    }

    fpTemp = tmpfile();

    while (fread(&temp, sizeof(Indexs), 1, fp) == 1)
    {
        if (strcmp(temp.nome, nome) != 0)
        {
            fwrite(&temp, sizeof(Indexs), 1, fpTemp);
        }
        else
        {
            encontrou = 1;
        }
    }

    if (!encontrou)
    {
        printf("Nome não encontrado.\n");
    }

    rewind(fpTemp);
    fp = freopen("index.dat", "wb", fp);

    while (fread(&temp, sizeof(Indexs), 1, fpTemp) == 1)
    {
        fwrite(&temp, sizeof(Indexs), 1, fp);
    }

    fclose(fp);
}

void mostrarDoArquivo()
{
    FILE *fp;
    // int n;
    Indexs temp;
    system("clear || cls");
    if ((fp = fopen("index.dat", "rb")) == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(-1);
    }
    while (fread(&temp, sizeof(Indexs), 1, fp) == 1)
    {
        printf("%s\n", temp.nome);
    }
    fclose(fp);
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
    printf("3. excluir nome\n");
    printf("0. Sair\n");
}

void gravar(Indexs *temp, const int n)
{
    FILE *fp;
    if ((fp = fopen("index.dat", "ab+")) == NULL)
    {
        printf("Conflito de arquivo");
        exit(-1);
    }
    // fwrite(&n, sizeof(int), 1, fp);
    fwrite(temp, sizeof(Indexs), n, fp);
    fclose(fp);
}
void inserir(Indexs *temp, const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Insira o nome: ");
        scanf("%*c%[^\n]s%*c", temp[i].nome);
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