# -*- coding: utf-8 -*-
"""
TP2 16/10

Python Sotirios Papadiamantis
"""

import numpy as np
import numpy.random as rd
import math
import matplotlib.pyplot as plt

#exo 2 

def Histogramme1(t,cases):
    """
    Returns an histogram that presents the number of times 
    t takes values in in an interval of [cases[i],cases[i+1]]
    or h[i]=#{k; t[k] belongs to [cases[i],cases[i+1]] }
    """


    h = np.zeros(cases.size)
    
    for i in range(0,cases.size-1):
        for k in range(0,t.size-1):

            if t[k]>=cases[i] and t[k]<cases[i+1]:
                h[i]+=1
        
        
    return h 

#exo3 
    
def Histogramme2(t,n):
    """
    Same as Histogram1 but setting cases as 
    cases[i] = t.min()+i*((t.max()-t.min())/(n-1))
    """
    
    cases = np.zeros(n)
    for i in range(0,n):
        cases[i] = t.min()+i*((t.max()-t.min())/(n-1))
        
    return Histogramme1(t,cases)

#exo4
def Histogramme3(t):
    """
    Returns a dictionary that associates all values found in t
    and 
    """
    unique, counts = np.unique(t, return_counts=True)
    return dict(zip(unique, counts))

    """Le dictionaire n'est pas une bonne solution quand beaucoup des valeurs sont uniques.
    En generale les dictionaires sont des structures des donnes vraiement vites 
    et utiles si le probleme a de valeurs discrets"""

    """
    #Alternative solution without using premade functions

    hdic = {}
    for i in range(0,len(t) - 1):
        if t[i] not in hdic:
            hdic[t[i]] = 1
        else:
            hdic[t[t]]+= 1
    return hdic
    """ 


#exo5
def Cumul(h):
    """
    Returns the cumulative histogram of h
    """
    hc = np.zeros(h.size)
    
    #For i in hc
    for i in range(0,hc.size):
        
        # Add every element in h up to h[i]
        for j in range(0,i):
            hc[i]+= h[j]
    return hc

#exo6

def Transformation(x):
    y = Histogramme2(x,200)
    y = y.astype('uint')
    return cs[y]


if __name__ == "__main__":

    '''
    TD2 main function
    '''


    #exo1
    # Creating a table that contains 1000 elements between 0 and 1 with uniform probability distribution
    Tu = rd.uniform(0,1,1000)
    # Creating a table that contains 1000 elements with uniform probability distribution of mean=0 and s=1
    Tg = rd.normal(0,1,1000)




    cases = np.linspace(-2,2,201)


    plt.figure()
    plt.plot(Histogramme1(Tu,cases))
    plt.title("Histogram 1 for Uniform dist")
    plt.show()

    plt.figure()
    plt.plot(Histogramme1(Tg,cases))
    plt.title("Histogram 1 for Gaussian dist")
    plt.show()
    print(Histogramme3(Tu))

    plt.figure()
    plt.plot(Histogramme2(Tu,200))
    plt.title("Histogram 2 for Uniform dist")
    plt.show()
    plt.figure()
    plt.plot(Histogramme2(Tg,200))
    plt.title("Histogram 2 for Gaussian dist")
    plt.show()

    plt.figure()
    plt.plot(Cumul(Histogramme2(Tu,200)))
    plt.title("Cumul for Uniform dist")
    plt.show()

    plt.figure()
    plt.plot(Cumul(Histogramme2(Tg,200)))
    plt.title(" Cumul for Gaussian dist")
    plt.show()

    global cs
    hist =  Histogramme2(Tg,200)
    cs = Cumul(hist)


    hist = hist.astype('uint')
    cs = cs.astype('uint')
    print(Histogramme2(Transformation(Tg),200))

    plt.figure()
    plt.plot(Histogramme2(Transformation(Tg),200))
    plt.title("Transformation for Gaussian dist")
    plt.show()
