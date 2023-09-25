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

    def __str__(self): 
        return ' '.join(str(i) for i in self.fila) #


fila = Fila()

while True:
    operacao = input(
        "Digite a operação (E para enfileirar, D para desenfileirar, - para sair): ")
    if operacao == 'E': #verifica se a operacao é E
        valor = int(input("Digite o valor a ser enfileirado: "))
        fila.enfileirar(valor)
    elif operacao == 'D': #verifica se a operacao é D
        fila.desenfileirar()
    elif operacao == '-': #verifica se a operacao é - e sai se for
        break
    print(fila)
