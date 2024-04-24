from tkinter import *


def criar_outra_janela():
    janela2 = Tk()
    janela2.geometry("300x200")
    janela2.title("janela 2")
    texto2 = Label(janela2, text="ola")
    texto2.grid(column=0, row=0, padx=0, pady=0)
    janela.destroy()

    chamararq = Button(janela2, text="chamar outra janela", command=None)
    chamararq.grid(column=1, row=1, padx=70, pady=50)
    janela2.mainloop()


janela = Tk()
janela.title("Cotação Atual de Moedas")
texto = Label(janela, text="Clique no botão para ver as cotações de moedas")
texto.grid(column=0, row=0, padx=10, pady=10)

botao = Button(janela, text="Buscar cotações", command=criar_outra_janela)
botao.grid(column=0, row=1, padx=10, pady=10)

texto_resposta = Label(janela, text="")
texto_resposta.grid(column=0, row=2, padx=10, pady=10)

janela.mainloop()
