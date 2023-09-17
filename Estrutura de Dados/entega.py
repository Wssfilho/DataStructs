class Fila:
    def __init__(self):
        self.fila = []
        self.max_fila = []

    def enfileirar(self, valor):
        while self.max_fila and self.max_fila[-1] < valor:
            self.max_fila.pop()
        self.fila.append(valor)
        self.max_fila.append(valor)

    def desenfileirar(self):
        if self.fila[0] == self.max_fila[0]:
            self.max_fila.pop(0)
        return self.fila.pop(0)


fila = Fila()
while True:
    operacao = input(
        "Digite a operação (E para enfileirar, D para desenfileirar, - para terminar): ")
    if operacao == 'E':
        valor = int(input("Digite o valor a enfileirar: "))
        fila.enfileirar(valor)
    elif operacao == 'D':
        fila.desenfileirar()
    elif operacao == '-':
        break
    print(fila.fila)
