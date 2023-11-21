# Definindo a classe No para armazenar os caracteres e suas frequências
class No:
    def __init__(self, caractere, frequencia):
        self.caractere = caractere
        self.freq = frequencia
        self.esquerda = None
        self.direita = None

# Função principal para a codificação de Huffman
def huff(texto: str):
    # Criando um dicionário para armazenar a frequência de cada caractere
    freqcaractere = {}
    for caractere in texto:
        if caractere not in freqcaractere:
            freqcaractere[caractere] = 0
        freqcaractere[caractere] += 1

    # Imprimindo a frequência de cada caractere
    print(f"Frequência de cada caractere: {freqcaractere}")

    # Criando uma lista de nós
    arvore_nos = [No(caractere, frequencia) for caractere, frequencia in freqcaractere.items()]

    # Loop para construir a árvore de Huffman
    while len(arvore_nos) > 1:
        # Ordenando os nós por frequência
        arvore_nos.sort(key=lambda x: x.freq)

        # Removendo os dois nós com menor frequência
        no_esquerda = arvore_nos.pop(0)
        no_direita = arvore_nos.pop(0)

        # Criando um novo nó que combina os dois nós removidos
        juncao_menores = No(None, no_esquerda.freq + no_direita.freq)
        juncao_menores.esquerda = no_esquerda
        juncao_menores.direita = no_direita

        # Adicionando o novo nó à lista de nós
        arvore_nos.append(juncao_menores)

    # A árvore de Huffman é o último nó na lista
    arvore_huffman = arvore_nos[0]

    # Dicionário para armazenar o código Huffman para cada caractere
    dicionario_codigo = {}

    # Função recursiva para gerar o código Huffman para cada caractere
    def codigo(no, codigo_atual=""):
        if no is None:
            return
        if no.caractere is not None:
            dicionario_codigo[no.caractere] = codigo_atual

        codigo(no.esquerda, codigo_atual + "0")
        codigo(no.direita, codigo_atual + "1")

    # Chamando a função obter_codigo para preencher o dicionário dicionario_codigo
    codigo(arvore_huffman)

    # Codificando o texto usando o dicionário dicionario_codigo
    texto_codificado = "".join([dicionario_codigo[caractere] for caractere in texto])

    # Retornando a árvore de Huffman, o dicionário dicionario_codigo e o texto codificado
    return arvore_huffman, dicionario_codigo, texto_codificado

# Solicitando ao usuário que insira o texto a ser codificado
texto = input("Digite o texto aqui: ")

# Chamando a função codificacao_huffman e imprimindo os resultados
arvore, dicionario, codificado = huff(texto)
print(f"Código Huffman para cada caractere: {dicionario}")
print(f"Texto codificado: {codificado}")
