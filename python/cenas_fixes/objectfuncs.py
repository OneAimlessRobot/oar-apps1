

from random import random

class Humano():
    def __init__(self,tristeza,alegria,capacity):
        self.ola=tristeza
        self.adeus=alegria
        self.lista=[]
        self.capacity=capacity
        #é assim que se cria uma lista vazia: com um par de parêntesis retos vazios.S
    def createList(self):
        for i in range(self.capacity):
            self.lista.append(Humano(int(random()*100),int(random()*100),self.capacity))
    def printList(self):
        self.createList()
        print(self.lista)
    
