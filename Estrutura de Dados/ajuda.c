#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 26

typedef struct //declaracao da estrutura da pilha
{
    int top;
    char vagoes[STACKSIZE];
} Stack;

int empty(Stack *ps); //funcao que verifica se a pilha esta vazia
int pop(Stack *ps);//remove e retorna item do topo da pilha;
void push(Stack *ps, int x); //insere o item x no topo da pilha
char *alocar(int n); //funcao de alocacao de vetor
void principal(char *operacoes, int n, char vagoes[]); //funcao que execulta o movimento dos itens dos vagoes
int main(void) //funcao main
{
    int n;
    char operacoes[STACKSIZE]; //variaveis
   

    printf("Insira o tamanho do vagao: ");
    scanf("%d", &n); //pedindo o tamanho do vagao principal
    fflush(stdin);
    char *vagoes = alocar(n); //alocando o vagao principal
    printf("Insira os vagoes: ");
    fgets(vagoes, n, stdin); //inserindo os dados
    fflush(stdin);
    printf("Insira as operacoes: ");
    fgets(operacoes, STACKSIZE, stdin); //inserindo as operacoes
    fflush(stdin);
    principal(operacoes, n, vagoes); //chamando a funcao principal
    printf("\n");

    

    free(vagoes); //liberando vetor alocado dinamicamente

    return 0;
}
void principal(char *operacoes, int n, char vagoes[])
{
    Stack trem_esq, trem_dir;
    trem_dir.top = -1; //declaracao das variaveis dos trilhos esquerda e direita
    trem_esq.top = -1;
    int i, j = 0; //var
    for(int k = 0; operacoes[k] != '\0'; k++)
    {
        if(operacoes[k] != 'E' || operacoes[k] != 'e' || operacoes[k] != 'D' ||operacoes[k] != 'd')
        {
            printf("Ha letra incompativel");
            exit(-1);
        }
    }
    for (i = 0; operacoes[i] != '\0'; i++) //for que verifica o vetor de instrucoes E e D ate o final do conteudo
    {
        if (operacoes[i] == 'E' || operacoes[i] == 'e') //se a posicao i no vetor operacoes for E, ele entra no if
        {
            if (j < n) //verificar se o vagao principal ainda tem conteudo para jogar ao trem da esquerda
            {
                push(&trem_esq, vagoes[j]); //retira a variavel do vagao principal e coloca no trem da esquerda
                j++; //variavel de controle
            }
            else //else se nao puder
            {
                printf("Não há mais vagões para mover.\n");
                break;
            }
        }
        else if (operacoes[i] == 'D' || operacoes[i] == 'd') //se for igual a D (mover para direita)
        {
            if (!empty(&trem_esq)) //verifica se esta vazia
            {
                push(&trem_dir, pop(&trem_esq)); //retira do trem da esquerda e poe no trem da direita
            }
            else //caso nao haja mais vagoes no trem da esquerda
            {
                printf("Não há mais vagões para mover.\n");
                break;
            }
        }
    }
    for (int i = 0; i <= trem_dir.top; i++) //printar o trem e os vagoes do lado direito na tela
    {
        printf("%c ", trem_dir.vagoes[i]);
    }

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
