class No:
    def __init__(self, cpf, nome):
        self.cpf = cpf
        self.nome = nome
        self.esquerda = None
        self.direita = None
        self.profundidade = 1


def inserir(raiz, cpf, nome):
    if raiz is None:
        return No(cpf, nome)
    else:
        if cpf < raiz.cpf:
            raiz.esquerda = inserir(raiz.esquerda, cpf, nome)
            raiz.esquerda.profundidade = raiz.profundidade + 1
        else:
            raiz.direita = inserir(raiz.direita, cpf, nome)
            raiz.direita.profundidade = raiz.profundidade + 1
        return raiz


def buscar(raiz, cpf):
    if raiz is None or raiz.cpf == cpf:
        return raiz
    if cpf < raiz.cpf:
        return buscar(raiz.esquerda, cpf)
    return buscar(raiz.direita, cpf)


def main():
    raiz = None
    n = int(input())
    for i in range(n):
        operacao = input().split()
        if operacao[0] == 'I':
            cpf = int(operacao[1])
            nome = input()
            raiz = inserir(raiz, cpf, nome)
        elif operacao[0] == 'B':
            cpf = int(operacao[1])
            no = buscar(raiz, cpf)
            print(f'{no.nome} {no.profundidade}')


if __name__ == "__main__":
    main()
