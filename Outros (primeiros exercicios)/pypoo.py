class Fila:
    def __init__(self):  # construtor do py
        self.fila = []

    def enfileirar(self, valor):
        self.fila.append(valor)

    def desenfileirar(self):
        if len(self.fila) > 0:
            maximo = max(self.fila)
            maxind = self.fila.index(maximo)
            self.fila.pop(maxind)
        else:
            print("A fila está vazia!")

    def __str__(self):
        return ' '.join(str(i) for i in self.fila)


fila = Fila()

while True:
    operacao = input(
        "Digite a operação: ")
    if operacao == 'E':
        valor = int(input("Digite o valor a ser enfileirado: "))
        fila.enfileirar(valor)
    elif operacao == 'D':
        fila.desenfileirar()
    elif operacao == '-':
        break
    print(fila)
