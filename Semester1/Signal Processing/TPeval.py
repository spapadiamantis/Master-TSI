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



# Exercise 7


def LocAv(t,n):
    """
    Local mean function. Calculates 1/2n+1 Σ[k+i]
    param y: a table of elements to apply local mean
    param n: factor of mean
    param yMoy: returns a table of size y with mean elements
    """


    # Create output table
    tAv = np.zeros_like(t)

    # For every element calculate mean average of 2*n+1 neighbours
    for k in range(n, len(t) - n):
        sum = 0

        # Add values of all neighbours
        for i in range(-n, n):
            sum += t[k + i]

        # Devided by number of elements
        tAv[k] = sum / (2 * n + 1)

    return tAv

# Exercise 9

def Convolution(x,t):
    """
    Simple convolution function
    param x: a 1-dimensional table
    param t: a 1-dimensional table
    return C the product of their convolution which has the same size
    """

    C = np.zeros_like(x)

    for i in range(0,t.size):
        sum = 0
        for k in range(0,x.size):
             sum  += t[k]*x[i-k]
        C[i] = sum

    return C


# Importing image
S = np.loadtxt("data1Signal.txt")


# Setting Flag for deterministic
flag = 0

# Check if every other realization has the exact same values
for i in range(0, 19):
    if np.array_equal(S[i],S[i+1])== False:
        flag = 1

if flag == 0:
    print("Deterministic Signal")
else:
    print("Non deterministic Signal")

# Ergodicity and Stationarity
stationnaire(S)
ergodique(S)

St = np.transpose(S)
print("Signal S transpose")
stationnaire(St)
ergodique(St)

T = np.loadtxt("data2Signal.txt")



plt.figure()
plt.plot(T)
plt.title("Initial Signal")
plt.show()


# Exercise 7

# Calculating and plotting Local Averages for different values of n


# n = 5
TAv = LocAv(T,5)

plt.figure()
plt.plot(TAv)
plt.title("Signal after Local Averages with n = 5")
plt.show()

# n = 10
TAv = LocAv(T,10)

plt.figure()
plt.plot(TAv)
plt.title("Signal after Local Averages with n = 10")
plt.show()

# n = 50
TAv = LocAv(T,50)

plt.figure()
plt.plot(TAv)
plt.title("Signal after Local Averages with n = 50")
plt.show()

# n = 100

TAv = LocAv(T,100)

plt.figure()
plt.plot(TAv)
plt.title("Signal after Local Averages with n = 100")
plt.show()




# Creating Impulse response h(t) = x(-t)
Xk = np.zeros_like(T)
Xk[0:100] = 1



plt.figure()
plt.plot(Xk[::-1])
plt.title("Impulse response for matched filter")
plt.show()


# Convolving with image and finding Max
C = Convolution(Xk[::-1],T)
t0 = np.argmax(C)
print(t0)
plt.plot(C)
plt.title("Convolution of h and x with my method")
plt.show()


# On confirme avec numpy

C1 = np.convolve(T,Xk[::-1], mode='full')
t0 = np.argmax(C1[T.size:])
print(t0)
plt.plot(C1[T.size:])
plt.title("Convolution of h and x with numpy")
plt.show()
