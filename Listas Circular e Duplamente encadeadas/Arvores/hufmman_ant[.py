# Definindo a classe No para armazenar os caracteres e suas frequências
class No:
    def __init__(self, caractere, frequencia):
        self.caractere = caractere
        self.frequencia = frequencia
        self.esquerda = None
        self.direita = None

# Função principal para a codificação de Huffman
def codificacao_huffman(texto):
    # Criando um dicionário para armazenar a frequência de cada caractere
    dicionario_frequencia = {}
    for caractere in texto:
        if caractere not in dicionario_frequencia:
            dicionario_frequencia[caractere] = 0
        dicionario_frequencia[caractere] += 1

    # Imprimindo a frequência de cada caractere
    print(f"Frequência de cada caractere: {dicionario_frequencia}")

    # Criando uma lista de nós
    nos = [No(caractere, frequencia) for caractere, frequencia in dicionario_frequencia.items()]

    # Loop para construir a árvore de Huffman
    while len(nos) > 1:
        # Ordenando os nós por frequência
        nos.sort(key=lambda x: x.frequencia)

        # Removendo os dois nós com menor frequência
        no_esquerda = nos.pop(0)
        no_direita = nos.pop(0)

        # Criando um novo nó que combina os dois nós removidos
        no_merge = No(None, no_esquerda.frequencia + no_direita.frequencia)
        no_merge.esquerda = no_esquerda
        no_merge.direita = no_direita

        # Adicionando o novo nó à lista de nós
        nos.append(no_merge)

    # A árvore de Huffman é o último nó na lista
    arvore_huffman = nos[0]

    # Dicionário para armazenar o código Huffman para cada caractere
    dicionario_codigo = {}

    # Função recursiva para gerar o código Huffman para cada caractere
    def obter_codigo(no, codigo_atual=""):
        if no is None:
            return

        if no.caractere is not None:
            dicionario_codigo[no.caractere] = codigo_atual

        obter_codigo(no.esquerda, codigo_atual + "0")
        obter_codigo(no.direita, codigo_atual + "1")

    # Chamando a função obter_codigo para preencher o dicionário dicionario_codigo
    obter_codigo(arvore_huffman)

    # Codificando o texto usando o dicionário dicionario_codigo
    texto_codificado = "".join([dicionario_codigo[caractere] for caractere in texto])

    # Retornando a árvore de Huffman, o dicionário dicionario_codigo e o texto codificado
    return arvore_huffman, dicionario_codigo, texto_codificado

# Solicitando ao usuário que insira o texto a ser codificado
texto = input("Digite o texto aqui: ")

# Chamando a função codificacao_huffman e imprimindo os resultados
arvore, dicionario, codificado = codificacao_huffman(texto)
print(f"Código Huffman para cada caractere: {dicionario}")
print(f"Texto codificado: {codificado}")