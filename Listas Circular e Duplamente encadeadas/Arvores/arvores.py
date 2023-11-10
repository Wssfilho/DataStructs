# A. função que calcula o número de folhas em uma árvore dada
# B. função recursiva que apaga todas as folhas de uma árvore que tenham a chave
# igual a um valor dado
# C. função que compara se duas árvores binárias são iguais

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

    def pre_ordem(raiz: No): #funcai para imprimir a arvore indo da raiz para a esquerda depois para a direita
        if raiz is not None:
            print(raiz.valor, end= '->')
            Arvore.pre_ordem(raiz.esquerda)
            Arvore.pre_ordem(raiz.direita)   
    ############# FUNCOES FEITA POR WILSON ################
    #funcao que remove as ocorrencias de folhas em uma arvore            
    def removefolhas(raiz: No, valor: int) -> No:
        if raiz is None: #verifica se esta vazia
            return None
        if raiz.esquerda is None and raiz.direita is None and raiz.valor == valor: #verifica na mesma raiz se é uma folha (esq e dir sao None) e se é a folha com o valor
            return None #remove a folha retornando none
        else:
            raiz.esquerda = Arvore.removefolhas(raiz.esquerda, valor) #faz recursivamente para achar todas as folhas com o valor indicado
            raiz.direita = Arvore.removefolhas(raiz.direita, valor)
        return raiz #se nao tiver nenhuma folha com o valor retorna a propia arvore 
    #função que calcula o número de folhas em uma árvore
    def qtdfolhas(raiz: No) -> int: 
        if raiz is None: #se a raiz nao existir retorna 0
            return 0
        if raiz.esquerda is None and raiz.direita is None: #se chegou na raiz onde esq e dir sao none retorna 1 pois e folha
            return 1
        return Arvore.qtdfolhas(raiz.esquerda) + Arvore.qtdfolhas(raiz.direita) #chama as funcoes para esq e dir recursivamente e soma cada valor
    
    #funcao para verificar se as duas sao iguais
    def verficar(raiz1: No, raiz2: No) -> int: 
            #nessa funcao pensei num modo de percorrer o mesmo lado nas duas folhas, e se a multiplicacao delas for 1 quer dizer que elas sao identicas
            #se for 0, 0.1 e zero, logo elas sao diferentes
            if raiz1 is None and raiz2 is None: #verifica se chegou no fim da arvore e se ambas sao none
                return 1
            if raiz1 is None or raiz2 is None: #verifica se uma ou outra e none, se uma for e a outra nao as arvores estao desbalanceadas
                return 0
            else:
                return Arvore.verficar(raiz1.esquerda, raiz2.esquerda) * Arvore.verficar(raiz1.direita, raiz2.direita) #Se ambas as recursoes retornarem 1 (indicando que as subárvores à esquerda e à direita são iguais), 
            #a função retorna 1. Se alguma delas forem 0, a multiplicacao fica 0 oq identifica desigualdade na comparacao das arvores
    
# Uso das funções criadas, funcao a
#1. 
ent1 = No(1)
print("Qtdfolhas 1: ", Arvore.qtdfolhas(ent1))
#2. 
novo_1 = No(7)
novo_2 = No(5)
novo_3 = No(7)
novo_4 = No(6)
novo_1 = No(8, novo_1, novo_2)
novo_5 = No(7, novo_3)
novo_3 = No(9, novo_4, novo_5)
novo_6 = No(5, None, novo_1)
novo_fim = No(6, novo_3, novo_6)
#Arvore.pre_ordem(novo_fim)
print("Qtdfolhas 2: ", Arvore.qtdfolhas(novo_fim))
#3. 
novo_5 = No(5)
novo_7 = No(7)
novo_6 = No(6)
novo_8 = No(8, novo_5, novo_7)
novo_7 = No(7, None, novo_8)
novo_9 = No(9, novo_6, None)
novo_com = No(6, novo_7, novo_9)
print("Qtdfolhas 3: ", Arvore.qtdfolhas(novo_com))

# Uso das funções criadas, funcao b
#1: 
novo_1 = No(1)

a: No = Arvore.removefolhas(novo_1, 1)
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
a: No = Arvore.removefolhas(novo_fim, 7)
if a is None:
    print("Lista se tornou vazia")
else:
    Arvore.pre_ordem(a)
    
#3
novo_5 = No(5)
novo_7 = No(7)
novo_8 = No(8, novo_5, novo_7)
novo_7 = No(7, None, novo_8)
novo_6 = No(6)
novo_9 = No(9, novo_6, None)
novo_in = No(6, novo_9, novo_7)
a: No = Arvore.removefolhas(novo_in, 7)
if a is None:
    print("Lista se tornou vazia")
else:
    print()
    Arvore.pre_ordem(a)
#teste da funcao comparar, funcao c:
#1

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
a = Arvore.verficar(novo_in1, novo_in2)
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
a = Arvore.verficar(novo_in1, novo_in2)
if a == 0:
    print("Falso")
elif a == 1:
    print("Verdadeiro")

