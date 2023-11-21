# A. função que calcula o número de folhas em uma árvore dada
# B. função recursiva que apaga todas as folhas de uma árvore que tenham a chave
# igual a um valor dado
# C. função que compara se duas árvores binárias são iguais

class No:
    """Esta classe representa um nó/elemento de uma árvore.
       Equivalente à função criar_arvore em C -- no slide
    """

    def __init__(self, valor, esquerda=None, direita=None):
        self.esquerda = None
        self.valor = valor
        self.esquerda = esquerda
        self.direita = direita


class Arvore:
    """Esta classe contem funções para a manipulação de árvores binárias."""

    def pre_ordem(self: No):  # function para imprimir a arvore indo da raiz para a esquerda depois para a direita
        if self is not None:
            print(self.valor, end='->')
            Arvore.pre_ordem(self.esquerda)
            Arvore.pre_ordem(self.direita)

    # funcao que remove as ocorrências de folhas em uma árvore
    def remove_folhas(self: No, valor: int) -> No | None:
        if self is None:  # verifica se esta vazia
            return None
        if self.esquerda is None and self.direita is None and self.valor == valor:  # verifica na mesma raiz se é 
            # uma folha (esq e dir sao None) e se é a folha com o valor
            return None  # remove a folha retornando none
        else:
            self.esquerda = Arvore.remove_folhas(self.esquerda,
                                                 valor)  # faz recursivamente para achar todas as folhas com o valor
            # indicado
            self.direita = Arvore.remove_folhas(self.direita, valor)
        return self  # se nao tiver nenhuma folha com o valor retorna a propria arvore

    # função que calcula o número de folhas em uma árvore
    def qtd_folhas(self: No) -> int:
        if self is None:  # se a raiz nao existir retorna 0
            return 0
        if self.esquerda is None and self.direita is None:  # se chegou na raiz onde esq e dir sao none retorna 1 
            # pois e folha
            return 1
        return Arvore.qtd_folhas(self.esquerda) + Arvore.qtd_folhas(
            self.direita)  # chama as funcoes para esq e dir recursivamente e soma cada valor

    # funcao para verificar se as duas sao iguais
    def verficar(self: No, raiz2: No) -> int:
        # nessa funcao pensei num modo de percorrer o mesmo lado nas duas folhas, 
        # e se a multiplicacao delas for 1 quer dizer que elas sao identicas
        # se for 0, 0.1 e zero, logo elas sao diferentes
        if self is None and raiz2 is None:  # verifica se chegou no fim da arvore e se ambas sao none
            return 1
        if self is None or raiz2 is None:  # verifica se uma ou outra e none, se 
            # uma for e a outra nao as árvores estao desbalanceadas
            return 0
        else:
            return Arvore.verficar(self.esquerda, raiz2.esquerda) * Arvore.verficar(self.direita,
                                                                                    raiz2.direita)  # Se ambas as recursoes
            # retornarem 1 (indicando que as subárvores à esquerda e à direita são iguais),
        # A função retorna 1. Se alguma delas forem 0, a fica 0 oq
        # identifica desigualdade na comparacao das árvores


# Uso das funções criadas, funcao a
# 1.
ent1 = No(1)
print("Qtd_folhas 1: ", Arvore.qtd_folhas(ent1))
# 2.
novo_1 = No(7)
novo_2 = No(5)
novo_3 = No(7)
novo_4 = No(6)
novo_1 = No(8, novo_1, novo_2)
novo_5 = No(7, novo_3)
novo_3 = No(9, novo_4, novo_5)
novo_6 = No(5, None, novo_1)
novo_fim = No(6, novo_3, novo_6)
# Arvore.pre_ordem(novo_fim)
print("Qtd_folhas 2: ", Arvore.qtd_folhas(novo_fim))
# 3.
novo_5 = No(5)
novo_7 = No(7)
novo_6 = No(6)
novo_8 = No(8, novo_5, novo_7)
novo_7 = No(7, None, novo_8)
novo_9 = No(9, novo_6, None)
novo_com = No(6, novo_7, novo_9)
print("Qtd_folhas 3: ", Arvore.qtd_folhas(novo_com))

# Uso das funções criadas, funcao b
# 1:
novo_1 = No(1)

a: No = Arvore.remove_folhas(novo_1, 1)
if a is None:
    print("Lista se tornou vazia")
else:
    Arvore.pre_ordem(a)

# 2:
novo_1 = No(7)
novo_2 = No(5)
novo_3 = No(7)
novo_4 = No(6)
novo_1 = No(8, novo_1, novo_2)
novo_5 = No(7, novo_3)
novo_3 = No(9, novo_4, novo_5)
novo_6 = No(5, None, novo_1)
novo_fim = No(6, novo_3, novo_6)
a: No = Arvore.remove_folhas(novo_fim, 7)
if a is None:
    print("Lista se tornou vazia")
else:
    Arvore.pre_ordem(a)

# 3
novo_5 = No(5)
novo_7 = No(7)
novo_8 = No(8, novo_5, novo_7)
novo_7 = No(7, None, novo_8)
novo_6 = No(6)
novo_9 = No(9, novo_6, None)
novo_in = No(6, novo_9, novo_7)
a: No = Arvore.remove_folhas(novo_in, 7)
if a is None:
    print("Lista se tornou vazia")
else:
    print()
    Arvore.pre_ordem(a)
# teste da funcao comparar, funcao c:
# 1

novo_5 = No(5)
novo_8 = No(8, None, novo_5)
novo_7 = No(7, novo_8, None)
novo_6 = No(6)
novo_9 = No(9, novo_6, None)
novo_in1 = No(6, novo_9, novo_7)

novo_5 = No(5)
novo_8 = No(8, None, novo_5)
novo_7 = No(7, None, novo_8)
novo_6 = No(6)
novo_9 = No(9, novo_6, None)
novo_in2 = No(6, novo_9, novo_7)
print()
a: int = Arvore.verficar(novo_in1, novo_in2)
if a == 0:
    print("Falso")
elif a == 1:
    print("Verdadeiro")
novo_5 = No(5)
novo_8 = No(8, None, novo_5)
novo_7 = No(7, novo_8, None)
novo_6 = No(6)
novo_9 = No(9, novo_6, None)
novo_in1 = No(6, novo_9, novo_7)
novo_5 = No(5)
novo_8 = No(8, None, novo_5)
novo_7 = No(7, novo_8, None)
novo_6 = No(6)
novo_9 = No(9, novo_6, None)
novo_in2 = No(6, novo_9, novo_7)
a: int = Arvore.verficar(novo_in1, novo_in2)
if a == 0:
    print("Falso")
elif a == 1:
    print("Verdadeiro")
