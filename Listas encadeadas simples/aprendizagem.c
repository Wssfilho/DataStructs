#include <stdio.h>
#include <stdlib.h>
#define n 10

struct elemento
{
    int valor;
    struct elemento *prox;
};
typedef struct elemento no;
typedef struct elemento *Pno;


void imprimir(Pno inicio) //SO IMPRIME
{
    Pno atual;
    atual = inicio;
    while(atual != NULL)
    {
        printf("[%d] ", atual->valor);
        atual = atual->prox;
    }
}
int vazia (Pno inicio)
{
    if (inicio==NULL)
        return 1;
    else
        return 0;
}

Pno criarElemento(int valor)
{
    Pno novo; //CRIACAO DE ESTRUTURA DO TIPO PONTEIRO COM NOME NOVO
    novo = (Pno) malloc (sizeof(no)); //ALOCA (1) ESPACO NA MEMORIA E APONTA AUTOMATICAMENTE DO TAMANHO DA ESTRUTURA
    if(novo == NULL)
        exit(0); //VERIFICA SE ALOCOU CERTO
    novo->valor = valor; //ENTAO ELE APONTA PARA O VALOR E COLOCA O VALOR
    novo->prox = NULL; //ELE APONTA PARA O NULLO ESTANDO PREPARADO PARA ALOCAR OUTRO ESPACO
    return novo; //RETORNA UM PONTEIRO PARA A NOVA ESTRUTUA QUE FOI ALOCADA
}
void inserirIn(Pno *inicio, Pno *novo)
{
    if(vazia(*inicio))
    {
        *inicio = *novo; //VERIFICA SE ESTA VAZIO, SE SIM ELE APONTA PARA UM NOVO
    }
    else
    {
        (*novo)->prox = *inicio; //SE NAO ESTA VAZIO ELE CRIA UM ESPACO E JA APONTA PARA O INICIO
        *inicio = *novo;
    }

}
void removerIn(Pno *inicio)
{
    if(!vazia(*inicio))
    {
        Pno alvo = *inicio;
        *inicio = alvo->prox;
        free(alvo);
    }
}
Pno busca(Pno *inicio, int x)
{
    Pno alvo = *inicio; //O ALVO APONTA PARA O INICIO
    while(alvo != NULL) //ENQUANTO O ALVO NAO FOR NULL, OU SEJA, ENQUANTO NAO ACABAR A LISTA!
    {
        if(alvo->valor == x) //COMPARA SE CADA VALOR DE CADA ESTRUTURA EH IGUAL AO VALOR INDICADO
            return alvo; //SE ACHAR JA RETORNA
        alvo = alvo->prox; //SE NAO ACHAR ELE CONTINUA ANDANDO
    }
    return alvo; //SE NAO TIVER O ELEMENTO ELE RETORNA A ESTRUTURA
    //(PODEMOS FAZER UMA FUNCAO QUE MOSTRA SE ALVO == 1 POR EXEMPLO E MOSTRAR UMA MENSAGEM QUE O ELEMENTO NAO ESTA NA LISTA)
}
void insereFim (Pno *inicio, Pno *novo){
	Pno ultimo;

	if (vazia(*inicio))
		*inicio = *novo;
	else {
		//percorre ate encontrar ultimo
		ultimo = *inicio;
		while (ultimo->prox != NULL)
			ultimo = ultimo->prox;

		ultimo->prox=*novo; //INSERE NO FIM
	}
}
//void removerFim();
//void concatenar
//void inserordenado
//void removeoalvo
int main(void)
{
    Pno inicio = NULL;
    Pno novo, alvo;
    for(int i = 0; i <= n; (i+=2)) //0 para par
    {
        novo = criarElemento(i);
        //inserirIn(&inicio, &novo);
        insereFim(&inicio, &novo);

    }
   /* for(int i = 1; i <= n; (i+=2)) //1 para impar
    {
        novo = criarElemento(i);
        //inserirIn(&inicio, &novo);
        insereFim(&inicio, &novo);

    }
    */

    imprimir(inicio);
    removerIn(&inicio);
    printf("\n\n\n\n");
    imprimir(inicio);
    alvo = busca(&inicio, 0); //SE FOR ZERO DA ERRO PQ O 0 JA FOI REMOVIDO NA FUNCAO ACIMA
    printf("\n%d", alvo->valor);
}