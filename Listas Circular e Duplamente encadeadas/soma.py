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
        while atual != None:
            print(atual.valor, end=' ')
            atual = atual.prox

    def somar(self, inicio1: No, ultimo2: No, valor):
        aux1: No = inicio1
        aux2: No = ultimo2
        i = 0
        while aux2.prox != None:
            aux2 = aux2.prox
        for i in range(valor):
            soma = aux1.valor + aux2.valor
            aux = No(soma)
            self.inserirFim(aux)
            if aux1.prox is not None:
                aux1 = aux1.prox

            if aux2.ant is not None:
                aux2 = aux2.ant
            i += 1


numero = int(input())
while numero != 0: #para quando e zero
    lista1 = Lista()
    lista2 = Lista()
    soma = Lista()
    print()
    x = input().split()
    x = [int(i) for i in x]

    for i in range(numero):
        novo = No(x[i])
        lista1.inserirFim(novo)
    x = input().split()
    x = [int(i) for i in x]
    for i in range(numero):
        novo = No(x[i])
        lista2.inserirFim(novo)

    soma.somar(lista1.inicio, lista2.inicio, numero)
    print()
    soma.mostrar()
    print()
    numero = int(input()) 


# inicializa uma lista vazia
