# criacao do objeto
class No:
    """Esta classe representa um nó/elemento de uma lista encadeada."""

    def __init__(self, valor, proximo=None, anterior=None):
        self.valor = valor
        self.prox = proximo
        self.ant = anterior


class Lista:
    """Esta classe contem funções para a manipulação de lista encadeada."""
    inicio = None

    def inserirFim(self, novo: No):
        if self.inicio == None:
            self.inicio = novo
        else:
            ultimo = self.inicio
            while ultimo.prox != None:
                ultimo = ultimo.prox

            ultimo.prox = novo
            novo.ant = ultimo

    def mostrar(self):
        atual = self.inicio
        while atual != None: #funcao mostrar que pecorre ate o ultimo
            print(atual.valor, end=' ')
            atual = atual.prox

    def somar(self, inicio1: No, ultimo2: No, valor): #somar recebe o propio objeto e os no das duas listas além do valor
        aux1: No = inicio1 #atribui as variaveis para fazer as operacoes
        aux2: No = ultimo2
        #i = 0
        while aux2.prox != None: #andarei na lista dois ate o final
            aux2 = aux2.prox
        for i in range(valor): #no tamanho da lista eu vou andando no for
            soma = aux1.valor + aux2.valor #faco a soma do primerio (lista 1) com o ultimo (lista 2)
            aux = No(soma)
            self.inserirFim(aux) #crio e insiro em uma nova lista
            if aux1.prox is not None: #se a lista 1 no proximo (frente -> fim) nao for vazio, entao anda
                aux1 = aux1.prox

            if aux2.ant is not None: #se a lista no anterior nao for vazio anda (fim -> frente)
                aux2 = aux2.ant
           # i += 1


numero = int(input()) #recebe o tamanho
while numero != 0: #para quando e zero!
    lista1 = Lista()
    lista2 = Lista() #cria as listas (duas para entrada, e uma para saida)
    soma = Lista()
    x = input().split()
    x = [int(i) for i in x] #recebe os dados

    for i in range(numero):
        novo = No(x[i])
        lista1.inserirFim(novo) #preenche as listas
    x = input().split()
    x = [int(i) for i in x]
    for i in range(numero):
        novo = No(x[i])
        lista2.inserirFim(novo)

    soma.somar(lista1.inicio, lista2.inicio, numero) #usa a lista auxiliar para somar
    print()
    print("saida: ")
    soma.mostrar()
    print("\n")
    numero = int(input()) #recebe o proximo numero de operacoes (tamanho), se for 0 sai


# inicializa uma lista vazia
