#criacao do objeto
class No:
    """Esta classe representa um nó/elemento de uma lista encadeada."""
    def __init__(self, valor, proximo=None, anterior=None):
        self.valor = valor  # Valor armazenado no nó
        self.prox = proximo  # Referência para o próximo nó
        self.ant = anterior  # Referência para o nó anterior (lista duplamente encadeada)

class Lista:
    """Esta classe contem funções para a manipulação de lista encadeada."""
    
    inicio=None  # Referência para o primeiro elemento da lista

    def inserirFim (self, novo: No):
        """Insere um novo nó no final da lista."""
        if self.inicio==None:  # Se a lista estiver vazia
            self.inicio=novo   # O novo nó se torna o primeiro elemento
        else:
            ultimo=self.inicio  # Começa no primeiro elemento
            # Percorre a lista até o último elemento
            while ultimo.prox!=None:
                ultimo=ultimo.prox

            ultimo.prox=novo   # Conecta o último elemento ao novo nó
            novo.ant=ultimo    # Conecta o novo nó ao último elemento (conexão bidirecional)

    def mostrar (self):
        """Exibe todos os elementos da lista."""
        atual=self.inicio
        while atual!=None:
            print(atual.valor, end=' ')
            atual=atual.prox

    def reverso(self):
        """Exibe os elementos da lista em ordem reversa (do último para o primeiro)."""
        # Encontra o último elemento da lista
        ultimo = self.inicio
        while ultimo.prox is not None:
            ultimo = ultimo.prox

        # Percorre a lista do último para o primeiro
        while ultimo is not None:
            print(ultimo.valor)
            # ERRO: Aqui está pulando um nó a cada iteração por causa do .ant.ant
            # Deveria ser apenas ultimo = ultimo.ant
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

# Chama o método reverso para exibir a lista de trás para frente
lista_1.reverso()  # Problema: este método está pulando elementos

