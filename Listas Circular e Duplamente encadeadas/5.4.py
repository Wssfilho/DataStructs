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

    def ocorrencias(self, k: int):
        occ = self.inicio
        while occ is not None:
            if (occ.valor % k) == 0:
                occ.ant.prox = occ.prox
                occ.prox.ant = occ.ant
            
