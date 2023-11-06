# Escreva uma função para deslocar o nó da posição i para frente em uma lista. 
# Por exemplo, dada a lista 10->20->21->22->, desloca-se o nó da posição 1 para frente, 
# resultando em 10->21->20->22->. Escolha qualquer lista encadeada de sua preferência, 
# simples ou duplamente encadeada, circular ou não. Considere que o nó a ser deslocado é
# um nó do meio (existe nós antes e depois dele) e considere que a posição i sempre existe na lista. 

class No:
    def __init__(self, valor, prox=None, ant=None):
        self.valor = valor
        self.ant = ant
        self.prox = prox #criação do Nó com lista duplamente encadeada


class Listaec:
    inicio = None

    def vazia(self):
        return self.inicio is None #verifica se é vazia

    def inserirFim(self, novo: No): #funcao insere o elemento no fim da lista
        if self.vazia():
            self.inicio = novo
        else:
            ultimo: No = self.inicio
            while ultimo.prox != None:
                ultimo = ultimo.prox
            ultimo.prox = novo
            novo.ant = ultimo

    def mostrar(self): #funcao que mostra a lista
        atual = self.inicio
        while atual != None:
            print(atual.valor, end='<->')
            atual = atual.prox

    def trocar(self, i): #funcao para fazer as trocas do nó
        if self.vazia(): #verifica se a lista e vazia
            return
        if self.inicio.prox is None: #se a lista so tem um elemento
            print("a lista so tem um elemento")
            return
        atual = self.inicio #atual recebe o inicio para nao perder a referencia do inicio
        j = 0 #variavel de controle
        while atual and j < i: #o while vai funcionar até que a variavel de controle seja igual ao numero que o usuario digitou, ele anda
            atual = atual.prox
            j += 1 #atualiza a var de controle
        if atual is None or atual.prox is None: #verifica se ja chegou no fim, ou se é o fim
            return #retorna se sim
        proximo = atual.prox #cria uma variavel proximo que rebe o atual em proximo, para ficar mais facil a manipulacao dos ponteiros sem perder referencia
        if atual.ant is None: #e o nó atual não tiver um nó anterior, significa que ele é o nó inicial da lista.
            self.inicio = proximo
            proximo.ant = None
        else:
            atual.ant.prox = proximo
            proximo.ant = atual.ant
        atual.prox = proximo.prox 
        if proximo.prox is not None: #Se o nó seguinte de proximo não for None, significa que proximo não é o nó final da lista.
            proximo.prox.ant = atual #atribue o ponteiro do proximo anterior ao atual
        proximo.prox = atual
        atual.ant = proximo

#inserir dados na lista
lista1 = Listaec()
laco = int(input("insira a quantidade dos elementos: "))  # funcao para pedir o tamanho da lista
for k in range(laco):
    novo = No(int(input("elemento: "))) #para cada elemento inserido é necessário ter um enter entre eles
    lista1.inserirFim(novo)

lista1.trocar(int(input("Insira o indece que quer mover: ")))
lista1.mostrar()
