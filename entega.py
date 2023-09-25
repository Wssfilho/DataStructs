def enfileirar(valor):
    fila.append(valor) #funcao para colocar um elemento na fila


def desenfileirar():
    if len(fila) > 0:
        maximo = max(fila)
        maximoind = fila.index(maximo)
        fila.pop(maximoind)
    else:
        print("A fila está vazia!") #printa se a fila esta vazia


fila = [] #cria a fila
while True: #enquanto for diferente de '-'
    operacao = input(
        "Digite a operação: ")
    if operacao == 'E':
        valor = int(input("Digite o valor a ser enfileirado: "))
        enfileirar(valor)
    elif operacao == 'D': #se a operacao for igual a 'D'
        desenfileirar()
    elif operacao == '-': #se for igual a '-' sai
        break 
    print(fila)
