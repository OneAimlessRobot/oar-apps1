from xmlrpc.client import Boolean
import objectfuncs as a
import mathfuncs as b
#Importo o modulo funcs.py (sem a extensão de ficheiro,claro) e dou-lhe um alias de "a". Posso chamar funções fazendo a.função() (como se fossem headers de C exepto que lhes posso dar nome)
import pyttsx3


def main():

    engine=pyttsx3.init("espeak",False)

    engine.setProperty('voice','english')
    engine.say("Hello there, mate!")
    engine.runAndWait()
    file=open("file.txt", "w")
    file.write(f"{derivative(b.numInv,0,0.01)}")



    #isto é um exemplo do que aparece quando tento dar print a uma lista que, neste caso, possui um numero inteiro (321) e um objeto do tipo "Humano"
    # [321, <funcs.Humano object at 0x7f8e15359580>]
    # Imprime o número e imprime o endereço do objeto na lista assim como o módulo e a classe a que ele pertence

    #colocar virgulas entre strings é uma forma de concatenar strings em python
    #Booleanos contam como ints ou floats na aritmetica em python.E não há comentários multilinhas.


def derivative(f,x,prec):
    return (f(x+prec)-f(x-prec))/prec

main()
