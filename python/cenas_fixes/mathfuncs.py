
def printPrimes():
    j=900
    while j<1000:
        i=1
        k=0
        while (i<=j):
            if(j%i==0):
                k=k+1
            i=i+1
        if(k==2):
            print(j)
        j=j+1



def square(x):
    return x*x

def numInv(x):
    return 1/x