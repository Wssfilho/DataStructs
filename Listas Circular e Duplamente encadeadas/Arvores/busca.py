class No:
    def __init__(self, nome, chave, esquerda, direita, cpf) -> None:
        self.chave = chave
        self.esq = esquerda
        self.dir = direita
        self.nome = nome
        self.cpf = cpf

class Arvore:
    def buscar(raiz, chave):
        if raiz is None or chave == raiz.chave:
            return raiz
        if chave < raiz.chave:
            return Arvore.buscar(raiz.esq, chave)
        else:
            return Arvore.buscar(raiz.dir, chave)
        
    def inserir(raiz, chave):
        if raiz is None:
            return No(chave)
        if chave < raiz.chave:
            raiz.esq = Arvore.inserir(raiz.esq, chave)
        else:
            raiz.dir = Arvore.inserir(raiz.dir, chave)
        return raiz
    def pre_ordem(self: No):  # function para imprimir a arvore indo da raiz para a esquerda depois para a direita
        if self is not None:
            print(self.valor, end='->')
            Arvore.pre_ordem(self.esquerda)
            Arvore.pre_ordem(self.direita)
            
for i in range(5):
    a = No(i)
    Arvore.inserir(a, 1)
