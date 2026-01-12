"""Implemente uma lista duplamente encadeada circular, 
onde o ponteiro de prox do último nó deve apontar para o início, 
bem como o ponteiro de anterior do início deve apontar para o último nó. 
Você não precisa implementar todas as funções, apenas a inserção no início, de forma a preservar essas características.
"""


class No:
    """Esta classe representa um nó/elemento de uma lista encadeada."""

    def __init__(self, valor, proximo=None, anterior=None):
        self.valor = valor
        self.prox = proximo
        self.ant = anterior


class Lista:
    """Esta classe contem funções para a manipulação de lista encadeada circular."""

    inicio = None

    def inserirInicio(self, novo: No):
        ult = self.inicio
        if self.inicio == None:
            self.inicio = novo
            self.inicio.prox = self.inicio #duplamente encadeada circular
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
            while ult.prox != self.inicio:
                ult = ult.prox
            ult.prox = novo
            novo.ant = ult
            novo.prox = self.inicio
            self.inicio.ant = novo

    def mostrar(self):
        atual = self.inicio
        while True:
            print(atual.valor, end=' ')
            atual = atual.prox
            if atual == self.inicio:
                return False


# inicializa uma lista vazia
lista_1 = Lista()

# Adiciona alguns nós
novo = No(10)
lista_1.inserirInicio(novo)

novo = No(13)
lista_1.inserirInicio(novo)

novo = No(20)
lista_1.inserirInicio(novo)

lista_1.mostrar()

# removendo e mostrando estado da lista
