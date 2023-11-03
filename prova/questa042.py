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
        j = 0
        if self.vazia():
            return
        else:
            andar = self.inicio
            while andar.prox != None:
                if (j == i):
                    andar.prox = andar.prox.prox
                    andar.prox.ant.ant = andar.ant
                    andar.ant = andar.prox.ant
                    andar.prox.ant.prox = andar.ant.ant.prox
                    andar.prox.ant = andar
                    andar.ant.ant.prox = andar.ant
                j += 1
                andar = andar.prox


lista1 = Listaec()
novo = No(10)
lista1.inserirFim(novo)
novo = No(20)
lista1.inserirFim(novo)
novo = No(21)
lista1.inserirFim(novo)
novo = No(22)
lista1.inserirFim(novo)
lista1.trocar(2)
lista1.mostrar()
