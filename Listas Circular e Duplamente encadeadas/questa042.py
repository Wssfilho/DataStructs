class No:
    def __init__(self, valor, prox = None, ant = None ):
        self.valor = valor
        self.ant = ant
        self.prox = prox


class Listaec:
    inicio = None

    def vazia(self):
        return self.inicio is None

    def inserirFim(self, novo: No):
        if self.vazia():
            self.inicio = novo
        else:
            ultimo: No = self.inicio
            while ultimo.prox != None:
                ultimo = ultimo.prox
            ultimo.prox = novo
            novo.ant = ultimo

    def mostrar(self):
        atual = self.inicio
        while atual != None:
            print(atual.valor, end='<->')
            atual = atual.prox

    def trocar(self, i):
        if self.vazia():
            return
        atual = self.inicio
        j = 0
        while atual and j < i:
            atual = atual.prox
            j += 1
        if atual is None or atual.prox is None:
            return
        proximo = atual.prox
        if atual.ant is None:
            self.inicio = proximo
            proximo.ant = None
        else:
            atual.ant.prox = proximo
            proximo.ant = atual.ant
        atual.prox = proximo.prox
        if proximo.prox is not None:
            proximo.prox.ant = atual
        proximo.prox = atual
        atual.ant = proximo

    
                


lista1 = Listaec()
novo = No(10)
lista1.inserirFim(novo)
novo = No(20)
lista1.inserirFim(novo)
novo = No(21)
lista1.inserirFim(novo)
novo = No(22)
lista1.inserirFim(novo)
lista1.trocar(1)
lista1.mostrar()
