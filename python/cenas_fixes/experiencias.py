
from random import randint


dict= {}


#!/usr/bin/env python

def main():

    
    print(func(1))

        







def func(x):
    if x==1:
        return x
    else:
        for i in range(3):
            z=func2(x+1)
        return z

def func2(x):
    if randint(1,9)==9:
        return x
    else: 
        for i in range(3):
            z= func(x+1)
        return z
    
main()
