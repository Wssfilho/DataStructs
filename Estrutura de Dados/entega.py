class Fila:
    def __init__(self):
        self.fila = []
        self.max_fila = []

    def enfileirar(self, valor):
        self.fila.append(valor)
        while self.max_fila and self.max_fila[-1] < valor:
            self.max_fila.pop()
        self.max_fila.append(valor)

    def desenfileirar(self):
        if self.fila:
            valor = self.max_fila.pop(0)
            self.fila.remove(valor)
            return valor
        return None

    def __str__(self):
        return ' '.join(str(i) for i in self.fila)

fila = Fila()

while True:
    operacao = input("Digite a operação (E para enfileirar, D para desenfileirar, - para sair): ")
    if operacao == 'E':
        valor = int(input("Digite o valor a ser enfileirado: "))
        fila.enfileirar(valor)
    elif operacao == 'D':
        fila.desenfileirar()
    elif operacao == '-':
        break
    print(fila)
