def empurrar(pilha, item):
    pilha.append(item)

def retirar(pilha):
    if not esta_vazia(pilha):
        return pilha.pop()
    else:
        print("ERRO - PILHA VAZIA")
        exit(1)

def esta_vazia(pilha):
    return len(pilha) == 0

def principal():
    n = int(input("Insira o tamanho do vagão: "))
    vagoes = input("Insira os vagoes: ")
    operacoes = input("Insira as operações: ")

    trem_esquerda = []
    trem_direita = []

    j = 0
    for operacao in operacoes:
        if operacao == 'E':
            if j < n:
                empurrar(trem_esquerda, vagoes[j])
                j += 1
            else:
                print("Não há mais vagões para mover.")
                break
        elif operacao == 'D':
            if not esta_vazia(trem_esquerda):
                empurrar(trem_direita, retirar(trem_esquerda))
            else:
                print("Não há mais vagões para mover.")
                break

    for vagao in trem_direita:
        print(vagao, end=' ')
    print()

if __name__ == "__main__":
    principal()
