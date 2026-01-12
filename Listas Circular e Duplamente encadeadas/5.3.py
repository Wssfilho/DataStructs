class No:
    """Esta classe representa um nó/elemento de uma lista encadeada."""

    def __init__(self, valor, proximo=None, anterior=None):
        self.valor = valor
        self.prox = proximo
        self.ant = anterior

#Implemente uma função que imprima uma lista na ordem reversa, porém pule sempre um elemento na impressão. Isto é, dada a lista:
#<- 1 <-> 2 <-> 3 <-> 4 <-> 5 ->

class Lista:
    """Esta classe contem funções para a manipulação de lista encadeada."""

    inicio = None

    def inserirInicio(self, novo: No):
        ult = self.inicio
        if self.inicio == None:
            self.inicio = novo
            self.inicio.prox = self.inicio
            # print(self.inicio.valor)
        else:
            novo.prox = self.inicio
            self.inicio.ant = novo
            while ult.prox != self.inicio:
                ult = ult.prox
            ult.prox = novo
            novo.ant = ult

    def mostrar(self):
        atual = self.inicio
        while True:
            print(atual.valor, end=' ')
            atual = atual.prox
            if atual == self.inicio:
                return False

    def mostrarOrdemReversa(self):
        ultimo = self.inicio
        i = 1
        while ultimo.prox != self.inicio:
            i += 1
            ultimo = ultimo.prox
        # print(i)
        if (i % 2) == 0:
            while True:
                print(ultimo.valor, end=' ')
                ultimo = ultimo.ant.ant
                if ultimo.ant == self.inicio:
                    print(ultimo.valor)
                    return False
        else:
            while True:
                print(ultimo.valor, end=' ')
                ultimo = ultimo.ant.ant
                if ultimo == self.inicio:
                    print(ultimo.valor)
                    return False


# inicializa uma lista vazia
lista_1 = Lista()

# Adiciona alguns nós
novo = No(1)
lista_1.inserirInicio(novo)

novo = No(2)
lista_1.inserirInicio(novo)

novo = No(3)
lista_1.inserirInicio(novo)

novo = No(4)
lista_1.inserirInicio(novo)

novo = No(5)
lista_1.inserirInicio(novo)
# novo = No(6)
# lista_1.inserirInicio(novo)

# novo = No(7)
# lista_1.inserirInicio(novo)

# novo = No(8)
# lista_1.inserirInicio(novo)

# novo = No(9)
# lista_1.inserirInicio(novo)
# novo = No(10)
# lista_1.inserirInicio(novo)


lista_1.mostrar()
print()
lista_1.mostrarOrdemReversa()

# removendo e mostrando estado da lista
