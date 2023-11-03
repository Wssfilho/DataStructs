class No:
    def __init__(self, dado=None):
        self.dado = dado
        self.proximo = None
        self.anterior = None


class ListaDuplamenteEncadeada:
    def __init__(self):
        self.cabeca = None

    def adicionar(self, dado):
        if not self.cabeca:
            self.cabeca = No(dado)
        else:
            atual = self.cabeca
            while atual.proximo:
                atual = atual.proximo
            atual.proximo = No(dado)
            atual.proximo.anterior = atual

    def exibir(self):
        elementos = []
        no_atual = self.cabeca
        while no_atual:
            elementos.append(no_atual.dado)
            no_atual = no_atual.proximo
        return elementos

    def mover_para_frente(self, i):
        atual = self.cabeca
        contador = 0
        while atual and contador < i:
            atual = atual.proximo
            contador += 1
        if atual is None or atual.proximo is None:
            return
        proximo_no = atual.proximo
        if atual.anterior is None:
            self.cabeca = proximo_no
            proximo_no.anterior = None
        else:
            atual.anterior.proximo = proximo_no
            proximo_no.anterior = atual.anterior
        atual.proximo = proximo_no.proximo
        if proximo_no.proximo is not None:
            proximo_no.proximo.anterior = atual
        proximo_no.proximo = atual
        atual.anterior = proximo_no
