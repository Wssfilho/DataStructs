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
//Precisamos encotrar o anterior ao alvo
void removeAlvo (Pno *inicio, Pno *alvo){
	Pno anterior = *inicio;
	
	if (!vazia(*inicio)){
		if (*inicio==*alvo){ // se alvo é elemento do início
			*inicio=(*inicio)->prox;
			free(*alvo);
		}
		else {	
			while (anterior->prox != *alvo)
				anterior = anterior->prox;		
			
			anterior->prox=(*alvo)->prox;	
			free(*alvo);
		}
	}
	
}
void removeFim(struct elemento **inicio){
	Pno alvo = *inicio;
	Pno anterior = *inicio;
	
	if (!vazia(*inicio)){
		while (alvo->prox != NULL){
			anterior = alvo;		
			alvo = alvo->prox;
		}
		anterior->prox=NULL;	
		free(alvo);
	}
}
//void concatenar
//void inserordenado
int main(void)
{
    Pno inicio = NULL;
    Pno novo, alvo, aux;
    int a;
    novo = criarElemento(1);
    inserirIn(&inicio, &novo);
    novo = criarElemento(2);
    inserirIn(&inicio, &novo);
    novo = criarElemento(2);
    inserirIn(&inicio, &novo);
    novo = criarElemento(3);
    inserirIn(&inicio, &novo);
    imprimir(inicio);
    scanf("%d", &a);
    aux = busca(&inicio, a);
    printf("%d", aux->valor);
    while(aux != NULL)
    {
        removeAlvo(&inicio, &aux);
        aux = busca(&inicio, a);
        printf("%d", aux->valor);
    }
    imprimir(inicio);

}