class Fila:
    def __init__(self):  # construtor do py
        self.fila = [] #cria a fila

    def enfileirar(self, valor): #funcao para colocar um elemento na fila
        self.fila.append(valor)

    def desenfileirar(self): #funcao desenfilerar
        if len(self.fila) > 0: #verifica se a fila não está vazia
            max_valor = max(self.fila) #pega o maior valor da fila
            max_index = self.fila.index(max_valor) #pega o index do maior valor
            self.fila.pop(max_index) # remove o maior valor da fila
        else:
            print("A fila está vazia!") #printa se a fila esta vazia


fila = Fila() #cria a fila

while True: #enquanto for diferente de '-'
    operacao = input(
        "Digite a operação (E para enfileirar, D para desenfileirar, - para sair): ")
    if operacao == 'E': #se a operacao for igual a 'E'
        valor = int(input("Digite o valor a ser enfileirado: "))
        fila.enfileirar(valor)
    elif operacao == 'D': #se a operacao for igual a 'D'
        fila.desenfileirar()
    elif operacao == '-':
        break #para se for igual a '-'
    print(fila)
