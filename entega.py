def enfileirar(valor):
    fila.append(valor) #funcao para colocar um elemento na fila


def desenfileirar(): #funcao desenfilerar
    if len(fila) > 0: #verifica se a fila não está vazia
        max_valor = max(fila) #pega o maior valor da fila
        max_index = fila.index(max_valor) #pega o indice do maior valor
        fila.pop(max_index) #remove o maior valor da fila
    else:
        print("A fila está vazia!") #printa se a fila esta vazia


fila = [] #cria a fila
while True: #enquanto for diferente de '-'
    operacao = input(
        "Digite a operação (E para enfileirar, D para desenfileirar, - para sair): ")
    if operacao == 'E': #se a operacao for igual a 'E'
        valor = int(input("Digite o valor a ser enfileirado: "))
        enfileirar(valor)
    elif operacao == 'D': #se a operacao for igual a 'D'
        desenfileirar()
    elif operacao == '-': #se for igual a '-' sai
        break 
    print(fila)
