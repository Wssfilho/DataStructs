class No:
    def __init__(self, freq, char, esquerda=None, direita=None):
        self.freq = freq
        self.char = char
        self.esquerda = esquerda
        self.direita = direita
    #def
# class Arvore:
#     inicio = None




vector = list()
entrada = ['a', 'b', 'a']
alfabeto = ['a', 'b']
for letra in alfabeto:
    num = entrada.count(letra)
    novo_no = No(num, letra, None, None)
    vector.append(novo_no)

for i in vector:
    print(i.freq)
