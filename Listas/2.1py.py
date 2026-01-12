# #Dada uma lista de números, crie duas outras listas para separar os números pares dos ímpares
# exemplo:
# lista_inicial=[10, 20, 33, 44, 55, 56, 66, 89]
# lista_par=[10, 20, 44, 56, 66]
# lista_impar=[33, 55, 89]

def inserir(valor):
    lista_inicial.append(valor)


def separar():
    while len(lista_inicial) > 0:
        a = lista_inicial[0] % 2
        if a == 0:
            b = lista_inicial.pop(0)
            lista_par.append(b)
        else:
            c = lista_inicial.pop(0)
            lista_impar.append(c)


lista_inicial = [10, 20, 33, 44, 55, 56, 66, 89]
lista_par = []
lista_impar = []

separar()
print(lista_inicial)
print(lista_par)
print(lista_impar)
