#criacao do objeto
class No:
    """Esta classe representa um nó/elemento de uma lista encadeada."""
    def __init__(self, valor, proximo=None, anterior=None):
        self.valor = valor
        self.prox = proximo
        self.ant = anterior

class Lista:
    """Esta classe contem funções para a manipulação de lista encadeada."""
    
    inicio=None  

    def inserirFim (self, novo: No):
        if self.inicio==None:
            self.inicio=novo
        else:
            ultimo=self.inicio
            while ultimo.prox!=None:
                ultimo=ultimo.prox

            ultimo.prox=novo
            novo.ant=ultimo

    def mostrar (self):
        atual=self.inicio
        while atual!=None:
            print(atual.valor, end=' ')
            atual=atual.prox
    def reverso(self):
        ultimo = self.inicio
        while ultimo.prox is not None:
            ultimo = ultimo.prox
        while ultimo is not None:
            print(ultimo.valor)
            if ultimo.ant is not None:
                ultimo = ultimo.ant.ant
            else:
                ultimo = ultimo.ant
        


#inicializa uma lista vazia
lista_1=Lista()

# Adiciona alguns nós
novo=No(1)
lista_1.inserirFim(novo)

novo=No(2)
lista_1.inserirFim(novo)

novo=No(3)
lista_1.inserirFim(novo)

novo=No(4)
lista_1.inserirFim(novo)

novo=No(5)
lista_1.inserirFim(novo)
lista_1.reverso()