"""
PAPADIAMANTIS Eval TP python
"""

import numpy as np
import matplotlib.pyplot as plt


def exo2(x,y):
    if x<y:
        return -1
    elif x == y:
        return 0
    else:
        return 1

def extermum_local(T):

    result = []

    # Check first
    print(np.abs(T[1]))
    if( np.abs(T[0]) > np.abs(T[1])):
        result.append((0,T[0]))

    # Check inbetween elements
    for i in range(1,T.shape[0]-1):
        if np.abs(T[i])>np.abs(T[i-1]) and np.abs(T[i+1])< np.abs(T[i]):
             result.append((i,T[i]))

    # Check last element
    if np.abs(T[-1])>np.abs(T[-2]):
        result.append((T.shape[0]-1,T[-1]))

    return result

def moyenne(T):

    # Calculate the sum of all elements of list
    somme = 0
    for i in range(0,T.shape[0]):
        somme += T[i]

    # Mean of elements
    m = somme / T.shape[0]
    return m

def Histogramme(T):
    # Allocating histogram
    H = np.zeros(256,dtype=int)

    # Get number of instances
    for k in range(0,T.size):
        H[T[k]] +=1

    return H

def exo8(H):
    somme = 0
    num = 0
    for i in range(0,H.shape[0]):
        somme += H[i]*i
        num += H[i]

    return  somme/num


def Coefficient(T, k):

    coeff = 0
    for i in range(0, T.size):
        coeff += T[i] * np.exp(-2j * np.pi * ((k * i) / T.size))

    return coeff

def TF(T):


    F = np.zeros(T.size, dtype=complex)

    for i in range(0, T.size):
        F[i] = Coefficient(T, i)

    return F

#Loadin text as ints
T = np.loadtxt("dataEvaluation.txt",dtype=int)

# Graph of Data in table t
plt.figure()
plt.plot(T)
plt.title("Data")
plt.show()

print("Extrema locale", extermum_local(T))


print("Moyenne de la fonction", moyenne(T))

hist = Histogramme(T.astype(int))


plt.figure()
plt.plot(hist)
plt.title("Histogramme")
plt.show()

print("Moyenne par hstogramme",exo8(hist))

plt.figure()
plt.plot(np.abs(TF(T)))
plt.title("Module Of Fourier transform")
plt.show()

