"""
TP Signal PAPADIAMANTIS Sotirios Part 1
"""

import numpy as np
import matplotlib.pyplot as plt


def stationnaire(S):
    """
    Function that returns a boolean variable concerning signal stationarity
    param S: a signal to be examined
    returns True if signal is stationary. Else returns false
    """

    # Transpose Matrix
    St = np.transpose(S)

    flag = 0

    # Getting overall statistical measures from signal
    mean = np.mean(St[0])
    # Uncomment to check for second order stationarity
    #std = np.std(St[0])

    # Check if statistical measures remain the same over the whole realisation
    for line in St:
        if np.mean(line) != mean:
              flag =1

    # If no flag has been raised return True
    if flag == 0:
        print("Signal stationnaire")
        return True
    else:
        print("Signal non stationnaire")
        return False




def ergodique(S):
    """
    Simple function that returns boolean variable concerning input signal
    ergodicity
    param S: input signal
    """

    flag = 0
    mean = np.mean(S[0])
    std = np.std(S[0])



    for line in S:
        if np.mean(line) != mean:
            flag=1

    if flag == 0:
        print("Signal ergodique")
    else:
        print("Signal non ergodique")


if __name__ == "__main__":

    #Exercise 3
    # Importing s from s1.csv
    s = np.loadtxt('s1.csv',dtype=float,delimiter=',')

    # Plotting graph
    plt.figure()
    plt.title("Signal s from s1.csv")
    plt.plot(s)
    plt.show()

    # On peut pas savoir si on a un signal deterministe vu que on a une seule
    # instance du signal. On a besoin plusiers experiences pour savoir si le signal
    # se repete

    #Exercise 4

    # Importing signal S with several realisations
    S = np.loadtxt('S.csv', dtype=float, delimiter=',')

    # Plots each realisation of S (Uncomment if necessairy)

    """
    for line in S:
        plt.figure()
        plt.title("Signal S")
        plt.plot(line)
        plt.show()
    """


    # Notre signal est deterministe car, pour chaque realization on
    # prend le meme resultat

    # Exercise 5
    # Examining signal stationarity
    stationnaire(S)

    #Exercise 6
    # Examining signal ergodicity
    ergodique(S)

    # Exercise 7
    """
    Vu que le signal S est un signal non stationaire mais ergodique, on sait que son transpose
    sera stationaire mais non ergodique
    """
    St = np.transpose(S)
    print("Checking stationarity and ergodicity of Transpose S")
    stationnaire(St)
    ergodique(St)