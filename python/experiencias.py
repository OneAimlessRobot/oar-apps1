
#!/usr/bin/env python

def main():

    import matplotlib.pyplot as plt
    import numpy as uma
    from mpl_toolkits.mplot3d import Axes3D

    x=uma.linspace(-10,10,100)
    y=uma.linspace(-10,10,100)
    z= 1/(x*x+y*y)

    fig = plt.figure()
    ax=fig.add_subplot(111, projection='3d')

    ax.plot(x,y,z)
    plt.show()






def sucessao(x):
    return x*x
    
main()
