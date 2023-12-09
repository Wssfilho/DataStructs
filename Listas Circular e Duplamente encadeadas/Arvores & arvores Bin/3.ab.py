class No:
    def __init__(self, valor, esq, dir, pai) -> None:
        self.dir = dir
        self.esq = esq
        self.valor = valor
        self.pai = pai
        
    def maximo(self):
        if self.dir is None:
            return self
        return self.dir.maximo()

    def antecessor(self):
        if self.esq is not None:
            return self.esq.maximo()
        else:
            return self.ancestral_esq()

    def ancestral_esq(self):
        if self.pai is None or self.pai.dir is self:
            return self.pai
        else: 
            return self.pai.ancestral_esq(self.pai)
    # Função para inserir um novo nó na árvore
    def inserir(raiz, cpf, nome):
        if raiz is None:  # Se a árvore estiver vazia, cria um novo nó
            return No(cpf, nome)  # retorna esse nó
        else:
            if cpf < raiz.cpf:  # Se o CPF for menor, insere a esquerda
                raiz.esquerda = No.inserir(raiz.esquerda, cpf, nome)
                raiz.esquerda.prof = raiz.prof + 1  # Atualiza a profundidade
            else:  # Se o CPF for maior, insere a direita
                raiz.direita = No.inserir(raiz.direita, cpf, nome)
                raiz.direita.prof = raiz.prof + 1  # Atualiza a profundidade
            return raiz  # Retorna a raiz da árvore

# Criando alguns nós
no1 = No(1, None, None, None)
no3 = No(3, None, None, None)
no2 = No(2, no1, no3, None)

# Atualizando os pais dos nós
no1.pai = no2
no3.pai = no2

# Agora no2 é a raiz da árvore, e no1 e no3 são seus filhos
arvore = no2

# Você pode agora chamar os métodos na raiz da árvore
print(arvore.maximo().valor)  # Deve imprimir 3
print(arvore.antecessor().valor)  # Deve imprimir 1
