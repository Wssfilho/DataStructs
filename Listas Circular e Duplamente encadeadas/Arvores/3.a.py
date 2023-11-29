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
