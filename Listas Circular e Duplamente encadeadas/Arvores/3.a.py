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