
#Implemente uma função que, dada uma lista, 
# retorne duas ou tras listas, a primeira com todos os elementos pares e a
# segunda com todos os elementos ímpares da lista inicial. Mantenha a ordem relativa dos elementos.


class No:
    """Esta classe representa um nó/elemento de uma lista encadeada."""

    def __init__(self, valor, proximo=None, anterior=None):
        self.valor = valor
        self.prox = proximo
        self.ant = anterior


class Lista:
    """Esta classe contem funções para a manipulação de lista encadeada."""

    inicio = None

    def inserirInicio(self, novo: No):
        ult = self.inicio
        if self.inicio == None:
            self.inicio = novo
            self.inicio.prox = self.inicio
            # print(self.inicio.valor)
        else:
            novo.prox = self.inicio
            self.inicio.ant = novo
            while ult.prox != self.inicio:
                ult = ult.prox
            ult.prox = novo
            novo.ant = ult

    def inserirFim(self, novo: No):
        ult = self.inicio
        if (self.inicio == None):
            self.inicio = novo
            self.inicio.prox = self.inicio
        else:
            novo.prox = self.inicio
            self.inicio.ant = novo
            while ult.prox != self.inicio:  
                ult = ult.prox
            ult.prox = novo
            novo.ant = ult

    def mostrar(self):
        atual = self.inicio
        while True:
            print(atual.valor, end=' ')
            atual = atual.prox
            if atual == self.inicio:
                return False


    def divisao(self):
        primeiro = self.inicio
        lista1 = Lista()
        lista2 = Lista()
        while primeiro.prox != self.inicio:
            if (primeiro.valor % 2) == 0:
                novo = No(primeiro.valor)
                lista1.inserirFim(novo)
            else:
                novo = No(primeiro.valor)
                lista2.inserirFim(novo)
            primeiro = primeiro.prox
        print("pares: ")
        lista1.mostrar()
        print()
        print("impares: ")
        lista2.mostrar()


Primeiro = Lista()
for i in range(20):
    novo = No(i)
    Primeiro.inserirFim(novo)
    #i+=1
Primeiro.divisao()
