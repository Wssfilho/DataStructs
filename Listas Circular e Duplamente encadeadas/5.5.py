

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
        lista1.mostrar()
        lista2.mostrar()


Primeiro = Lista()
novo = No(1)
Primeiro.inserirFim(novo)
novo = No(2)
Primeiro.inserirFim(novo)
novo = No(3)
Primeiro.inserirFim(novo)
novo = No(4)
Primeiro.inserirFim(novo)
novo = No(5)
Primeiro.inserirFim(novo)
Primeiro.divisao()
