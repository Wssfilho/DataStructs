def enfileirar(valor):
    fila.append(valor)


def desenfileirar():
    if len(fila) > 0:
        max_valor = max(fila)
        max_index = fila.index(max_valor)
        fila.pop(max_index)
    else:
        print("A fila está vazia!")


fila = []
while True:
    operacao = input(
        "Digite a operação (E para enfileirar, D para desenfileirar, - para sair): ")
    if operacao == 'E':
        valor = int(input("Digite o valor a ser enfileirado: "))
        enfileirar(valor)
    elif operacao == 'D':
        desenfileirar()
    elif operacao == '-':
        break
    print(fila)
