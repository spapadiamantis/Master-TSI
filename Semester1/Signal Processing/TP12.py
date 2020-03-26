"""
TP Signal PAPADIAMANTIS Sotirios Part 2
"""

import numpy as np
import matplotlib.pyplot as plt
import math
from scipy import signal

def SignalDistance(s1,s2):
	"""
	Simple function to calculate distance between two signals of same length
	param s1: first input signal
	param s2: second input signal
	"""
	dist = 0

	# calculate absolute distance between each element
	for i in range(0, len(s1)):
		dist += np.abs(s1[i] - s2[i])
	return dist


# Exercise 9

def moyenneLocale(y,n):
	"""
	Local mean function. Calculates 1/2n+1 Σ[k+i]
	param y: a table of elements to apply local mean
	param n: factor of mean
	param yMoy: returns a table of size y with mean elements
	"""

	# Create output table
	yMoy = np.zeros_like(y)

	# For every element calculate mean average of 2*n+1 neighbours
	for k in range(n,len(y)-n):
		sum = 0

		# Add values of all neighbours
		for i in range(-n,n):
			sum += y[k+i]

		# Devided by number of elements
		yMoy[k] = sum/(2*n+1)

	return yMoy

#Exercise 10

# Create a convolution array
# n must create a square matrix

def conv_array(n):
	"""
	This function returns a square convolution kernel of size n,
	where each element has a value of 1/n
	"""

	# Allocate kernel
	conv = np.zeros(n)

	# Give values to elements
	for i in range(0,n-1):
		conv[i] = 1/n

	return conv

#Exercise 11

# Create various convolution kernels
def diagonal_conv(n):
	"""
	This function returns a square convolution kernel of size n,
	where all elements of the diagonal have values of 1
	"""

	# Building bi-dimensional array
	lim = int(math.sqrt(n))
	conv = np.zeros((lim,lim))

	# If element on diagonal set to 1/lim
	for i in range(0,lim ):
		for  j in range(0,lim ):
			if j == i:
				conv[i,j]= 1/lim

	# Reshape to uni-dimensional array
	conv = np.reshape(conv,n)

	return conv


def Gaussian_conv(n):
	"""
	This function returns a square convolution kernel of size n,
	where all elements follow the normal distribution
	"""

	# Choose sigma and mu
	sigma = 1
	mu = 0

	# Create table
	b = sigma * np.random.randn(n) + mu
	sum = b.sum()
	#b = b/sum
	print(b)
	return b

if __name__ == "__main__":

	# Exercise 8

	# Initial subject with data import

	# reponse: la moyenage de valeurs
	x = np.loadtxt("data.csv",dtype=float,delimiter=',')

	plt.figure()
	plt.title("Gate signal x")
	plt.plot(x)
	plt.show()


	plt.figure()
	# On prendre le module de la transforme pour ne pas perdre les info dans la partie imaginaire
	plt.plot(np.abs(np.fft.fft(x)))
	plt.title("Fourrier Transform")
	plt.show()


	# Create a gate signal
	sigma = 2
	mu = 0
	b = sigma * np.random.randn(100) + mu

	porte = np.zeros_like(b)

	porte[30:60] = 1

	x2 = porte + b
	plt.figure()
	plt.plot(x2)
	plt.title("Signal X variance=1 small gate")
	plt.show()

	"""
	Afin de pouvoir filtrer le signal il faut soustracter la valeur 
	du bruit de chaque element du signal x(t).
	"""

	plt.figure()
	plt.plot(moyenneLocale(x, 5))
	plt.title("Methode Moyennes Locales")
	plt.show()

	plt.figure()
	plt.plot(np.abs(np.fft.fft(moyenneLocale(x, 5))))
	plt.title("Methode Moyennes Locales avec 5 voisins")
	plt.show()

	"""
	La distance entre le signal porte est le signal produit du moyennage local
	diminue jusqu une valeur optimale (n=25). Pour n>25 la distance reaugment. Dans nos
	experiences on a un signal du longeur 100. C'est pour cela que le resultat change pas pour n>50
	"""
	moyennes = np.arange(1,100,5);
	sdists = []


	for i in range(0,len(moyennes)):
		sdists.append(SignalDistance(porte,moyenneLocale(x2, moyennes[i])))



	plt.figure
	plt.title('Mean local - multiple realizations')
	plt.ylabel('Distance from Gate signal')
	plt.xlabel('Value of n chosen')
	plt.plot(moyennes,sdists)
	plt.grid()
	plt.show()


	# Convolutions

	# Getting convolution kernel
	conv = conv_array(9)

	plt.figure()
	plt.plot(np.convolve(x,conv))
	plt.title("Convolution with simple array")
	plt.show()

	plt.figure()
	plt.plot(np.abs(np.fft.fft(np.convolve(x,conv))))
	plt.title("Fourrier Transform after convolution")
	plt.show()

	# Diagonal convolution kernel
	conv = diagonal_conv(9)


	plt.figure()
	plt.plot(np.convolve(x,conv))
	plt.title("Convolution with diagonal array")
	plt.show()

	plt.figure()
	plt.plot(np.abs(np.fft.fft(np.convolve(x,conv))))
	plt.title("Fourrier Transform after convolution")
	plt.show()

	# Gaussian convolution kernel
	conv = Gaussian_conv(9)


	plt.figure()
	plt.plot(np.convolve(x,conv))
	plt.title("Convolution with Gaussian noise kernel")
	plt.show()

	plt.figure()
	plt.plot(np.abs(np.fft.fft(np.convolve(x,conv))))
	plt.title("Fourrier Transform after convolution")
	plt.show()



	# Partie 2

	#exercise 13
	# h(t) = (k/σ^2)X*(f)exp(-j2πfT) h(t) = porte(-t)

	filtre = np.zeros_like(porte)
	filtre[0:30] = 1
	#h = 1/4*filtre

	plt.figure()
	plt.plot(filtre[::-1])
	plt.title("Impulse Response of x")
	plt.show()

	#Exo 16

	# Convolution with h(-t)

	find = np.convolve(x2,filtre[::-1],mode='full')

	# Finding Tzero from peak
	tzero = np.argmax(find[x2.size:])


	print("Tzero is ",tzero)


	plt.plot(find[x2.size:])
	plt.title("Convolution of h and x")
	plt.show()

	#Exo17

	# Comparative study with various gate sizes and sigmas for noise

	larg = np.arange(30 , 72 , 10)
	print("This is Large " , larg)
	slist = np.arange(2,11,2)
	result1 = []


	for i in range(0,5):
		sigma = 2
		mu = 0
		b = sigma * np.random.randn(1000) + mu

		porte = np.zeros_like(b)

		porte[50:(50+larg[i])] = 1
		x2 = porte+b
		filtrei = np.zeros(larg[i])
		filtrei[0:30] = 1
		find = np.convolve(x2, filtre[::-1], mode='full')

		tzero = np.argmax(find[x2.size:])

		result1.append(tzero)

	result2 = []
	for i in range(0, 5):
		sigma = slist[i]
		mu = 0
		b = sigma * np.random.randn(1000) + mu

		porte = np.zeros_like(b)

		porte[50:50 + 30] = 1
		x2 = porte + b
		filtrei = np.zeros(larg[i])
		filtrei[0:30] = 1
		find = np.convolve(x2, filtre[::-1], mode='full')

		tzero = np.argmax(find[x2.size:])


		result2.append(tzero)


	for i in range(0,5):
		result1[i] = np.abs(result1[i]-50)
		result2[i] = np.abs(result2[i]-50)


	plt.figure()
	plt.plot(larg,result1)
	plt.title("largeur to distance Variance = 2")
	plt.show()

	plt.figure()
	plt.plot(slist,result2)
	plt.title("variance to distance, Largeur = 30")
	plt.show()

	#Exo18

	# Filtering in the frequential domain
	H = np.fft.fft(filtre[::-1])


	plt.figure()
	plt.plot(H)
	plt.title("Impulse Response of H")
	plt.show()

	X  = np.fft.fft(x2);

	find = np.convolve(X,H)
	tzero = np.argmax(find[X.size:])
	""""
	max = find.max()

	for i in range(0,len(find)):
		if find[i] == max:
			tzero = i;
	"""



	print(tzero)
	plt.plot(find)
	plt.title("Convolution of H and X")
	plt.show()
