# Definindo a classe No
class No:
    def __init__(self, cpf, nome):
        self.prof = 1  # Profundidade do nó na árvore
        self.cpf = cpf 
        self.nome = nome
        self.direita = None  # Nó filho a direita 
        self.esquerda = None  # Nó filho a esquerda


# Função para inserir um novo nó na árvore
def inserir(raiz, cpf, nome):
    if raiz is None:  # Se a árvore estiver vazia, cria um novo nó
        return No(cpf, nome)  # retorna esse nó
    else:
        if cpf < raiz.cpf:  # Se o CPF for menor, insere a esquerda
            raiz.esquerda = inserir(raiz.esquerda, cpf, nome)
            raiz.esquerda.prof = raiz.prof + 1  # Atualiza a profundidade
        else:  # Se o CPF for maior, insere a direita
            raiz.direita = inserir(raiz.direita, cpf, nome)
            raiz.direita.prof = raiz.prof + 1  # Atualiza a profundidade
        return raiz  # Retorna a raiz da árvore


# Função para buscar um nó na árvore
def buscar(raiz, cpf):
    if raiz is None or raiz.cpf == cpf:  # Se a árvore estiver vazia ou o CPF for encontrado, retorna o nó
        return raiz
    if cpf < raiz.cpf:  # Se o CPF for menor, busca a esquerda
        return buscar(raiz.esquerda, cpf)
    return buscar(raiz.direita, cpf)  # Se o CPF for maior, busca a direita

# Inicializando a árvore
raiz = None
n = int(input())  # Lendo o número de operações
for i in range(n):
    operacao = input().split()  # Lendo a operação
    if operacao[0] == 'I':  # Se a operação for de inserção
        cpf = int(operacao[1])  # Lendo o CPF
        nome = input()  # Lendo o nome
        raiz = inserir(raiz, cpf, nome)  # Inserindo o nó na árvore
    elif operacao[0] == 'B':  # Se a operação for de busca
        cpf = int(operacao[1])  # Lendo o CPF
        no = buscar(raiz, cpf)  # Buscando o nó na árvore
        print(f'{no.nome} {no.prof}')  # Imprimindo o nome e a profundidade do nó

