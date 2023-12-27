class pessoa:
    def __init__(self, nome, idade) -> None:
        self.nome = nome
        self.idade = idade
        
    def mostrar(self) -> None:
        print(self.nome)
        print(self.idade)
        

nome = input("insira o nome")
idade = input("insira a idade")
pessoa = pessoa(nome, idade)
pessoa.mostrar()
        