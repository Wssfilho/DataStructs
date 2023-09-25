def enfileirar(valor):
    fila.append(valor)


def desenfileirar():
    if len(fila) > 0:
        maximo = max(fila)
        maximoind = fila.index(maximo)
        fila.pop(maximoind)
    else:
        print("A fila está vazia!")


fila = []
while True:
    operacao = input(
        "Digite a operação:")
    if operacao == 'E':
        valor = int(input("Digite o valor a ser enfileirado: "))
        enfileirar(valor)
    elif operacao == 'D':
        desenfileirar()
    elif operacao == '-':
        break
    print(fila)
