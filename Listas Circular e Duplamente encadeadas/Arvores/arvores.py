class No:
    """Esta classe representa um nó/elemento de uma árvore.
       Equivalente a função criar_arvore em C -- no slide
    """

    def __init__(self, valor, esquerda=None, direita=None):
        self.valor = valor
        self.esquerda = esquerda
        self.direita = direita


class Arvore:
    """Esta classe contem funções para a manipulação de árvores binárias."""

    # Recebe um Nó de uma árvore (raiz local) e um inteiro.
    # Retorna o No que contem o valor inteiro.
    def procurar_no(raiz: No, x: int) -> No:
        if raiz is None:
            return None

        if raiz.valor == x:
            return raiz

        esq = Arvore.procurar_no(raiz.esquerda, x)
        if (esq is not None):
            return esq

        _dir = Arvore.procurar_no(raiz.direita, x)
        if (_dir is not None):
            return _dir

        return None

    def numero_nos(raiz: No) -> int:
        if raiz is None:
            return 0
        n_esq = Arvore.numero_nos(raiz.esquerda)
        n_dir = Arvore.numero_nos(raiz.direita)
        return n_esq+n_dir+1

    def altura(raiz: No) -> int:
        if raiz is None:
            return 0
        h_esq = Arvore.altura(raiz.esquerda)
        h_dir = Arvore.altura(raiz.direita)
        return 1 + max(h_esq, h_dir)

    def pre_ordem(raiz: No):
        if raiz is None:
            print("vazia")
            return
        if raiz is not None:
            print(raiz.valor, end=' ')
            Arvore.pre_ordem(raiz.esquerda)
            Arvore.pre_ordem(raiz.direita)

    def pos_ordem(raiz: No):
        if raiz is not None:
            Arvore.pos_ordem(raiz.esquerda)
            Arvore.pos_ordem(raiz.direita)
            print(raiz.valor, end=' ')

    def in_ordem(raiz: No):
        if raiz is not None:
            Arvore.in_ordem(raiz.esquerda)
            print(raiz.valor, end=' ')
            Arvore.in_ordem(raiz.direita)

    def percurso_em_largura(raiz: No):
        f = list()
        f.append(raiz)  # insere no fim
        while len(f) > 0:
            raiz = f.pop(0)  # removo no início
            if raiz is not None:
                f.append(raiz.esquerda)
                f.append(raiz.direita)
                print(raiz.valor, end=' ')
                
    def removefolha(raiz: No, valor: int) -> No:
        if raiz.esquerda is None and raiz.direita is None and raiz.valor == valor:
            return None
        else:
            raiz.esquerda = Arvore.removefolha(raiz.esquerda, valor)
            raiz.direita = Arvore.removefolha(raiz.direita, valor)
        return raiz
# Uso das funções criadas
novo_1 = No(1)


# árvore montada na variável novo_2:
#       50
# 40        20
#         10   30

num = int(input())
Arvore.removefolha(novo_1, num)
Arvore.pre_ordem(novo_1)

