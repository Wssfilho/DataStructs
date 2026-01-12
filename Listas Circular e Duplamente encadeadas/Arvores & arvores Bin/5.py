# Definindo a classe No
class No:
    def __init__(self, valor):
        self.prof = 1  # Profundidade do nó na árvore
        self.valor = valor
        self.direita = None  # Nó filho a direita 
        self.esquerda = None  # Nó filho a esquerda

class Arvorebusc:
# Função para inserir um novo nó na árvore
    def inserir(raiz, valor):
        if raiz is None:  # Se a árvore estiver vazia, cria um novo nó
            return No(valor)  # retorna esse nó
        else:
            if valor < raiz.valor:  # Se o CPF for menor, insere a esquerda
                raiz.esquerda = Arvorebusc.inserir(raiz.esquerda, valor)
                raiz.esquerda.prof = raiz.prof + 1  # Atualiza a profundidade
            else:  # Se o CPF for maior, insere a direita
                raiz.direita = Arvorebusc.inserir(raiz.direita, valor)
                raiz.direita.prof = raiz.prof + 1  # Atualiza a profundidade
            return raiz  # Retorna a raiz da árvore


    # Função para buscar um nó na árvore
    def buscar(raiz, valor):
        if raiz is None or raiz.valor == valor:  # Se a árvore estiver vazia ou o CPF for encontrado, retorna o nó
            return raiz
        if valor < raiz.valor:  # Se o CPF for menor, busca a esquerda
            return Arvorebusc.buscar(raiz.esquerda, valor)
        return Arvorebusc.buscar(raiz.direita, valor)  # Se o CPF for maior, busca a direita
    def imprimir_inverso(raiz):
        if raiz:
            # Primeiro recursão na subárvore direita
            Arvorebusc.imprimir_inverso(raiz.direita)

            # Em seguida, imprime o valor do nó
            print(raiz.valor, end= ' ')

            # Finalmente, recursão na subárvore esquerda
            Arvorebusc.imprimir_inverso(raiz.esquerda)
    def imprimir_intervalo(raiz, min_val, max_val):
        if raiz:
            # Primeiro recursão na subárvore esquerda
            if min_val < raiz.valor:
                Arvorebusc.imprimir_intervalo(raiz.esquerda, min_val, max_val)

            # Em seguida, imprime o valor do nó se estiver no intervalo
            if min_val <= raiz.valor and raiz.valor <= max_val:
                print(raiz.valor, end= ' ')

            # Finalmente, recursão na subárvore direita
            if max_val > raiz.valor:
                Arvorebusc.imprimir_intervalo(raiz.direita, min_val, max_val)
            
            
            

# Inicializando a árvore
novoinsere = None
novoinsere = Arvorebusc.inserir(novoinsere, 2)
novoinsere = Arvorebusc.inserir(novoinsere, 3)
novoinsere = Arvorebusc.inserir(novoinsere, 4)
novoinsere = Arvorebusc.inserir(novoinsere, 1)
no = Arvorebusc.buscar(novoinsere, 4)  # Buscando o nó na árvore
print("profundidade: " f'{no.valor} {no.prof}')  # Imprimindo o nome e a profundidade do nó
Arvorebusc.imprimir_inverso(novoinsere)
print()
Arvorebusc.imprimir_intervalo(novoinsere, 1, 3)

