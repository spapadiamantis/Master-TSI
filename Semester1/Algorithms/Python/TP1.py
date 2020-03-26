"""
Python TP1 PAPADIAMANTIS Sotirios
"""


import math


def ex1_lire_data(path):
    """ 
    Read input data from file
    in path
    """

    # Open file to read list 
    f = open(path,'r')

    # Read file per line into list
    lines = []
    lines = f.readlines()

    l = []
    # Convert list of strings to list of floats
    for i in range(len(lines)):
         l.append(float(lines[i][:-1]))

    # Close file
    f.close()

    return l

def ex2_afficher_n_val(list,n):
    """
    Print first n elements of list
    """

    print("Les {} premiers éléments de L sont :".format(n), end=" ")

    # Traverses list and prints each element
    for i in range(0,n):
         print(list[i],end=" ")
    print('\n')

def ex3_stocker_n_au_fichier(list,n):
    """
    Save list to file
    """

    # Get path for data file from user
    data_path = input("Donnez un chemin de fichier ")

    # Open file for writing
    f=open(data_path,"w")

    # Convert list of floats to string
    l = []
    for i in range(0,len(list)):
         l.append(str(list[i]))

    # Write an item per line
    for i  in range(0,n+1):
         f.write(l[i])
         f.write("\n")

    # Close file
    f.close()
  
def ex4_maximum(list):
    """
    Returns maximum from lis
    """

    # Set starting value for max variable
    max = list[0]

    # For each item in list
    for i in range(0,len(list)):

        # If current element is greater set as max
        if max<list[i]:
             max = list[i]
    # Return max
    return max


def ex5_maximum_locaux(list):
    """
    Finds local maximums in a list of numbers
    """

    print("Voila les maximums locaux")
    print()

    # Check is first element is local max
    if list[0] > list[1]:
         print("({:.3f},{})".format(list[0],0))

    # Check inbetween elements
    for i in range(1,len(list)-1):
         if list[i]>list[i-1] and list[i+1]<list[i]:
              print("({:.3f},{})".format(list[i],i))

    # Check last element
    if list[-1]>list[-2]:
         print("({:.3f},{})".format(list[-1],len(list)))

    print()

def ex6_norme_euclidienne(list):

    """
    Returns Euclidean Norm of a sampled function
    """

    # Sum of squares all values in list
    somme = 0
    for i in range(len(list)):
         somme+= list[i]**2
    

    # Calculate squared root
    norm = math.sqrt(somme)
    
    return norm

def ex7_moyenne_et_variance(list):

    """
    Returns mean and variance of a sampled function
    in form of list
    """

    # Calculate the sum of all elements of list
    somme = 0 
    for i in range(len(list)):
        somme+= list[i]

    # Mean = Sum/Number of elements
    m = somme/len(list)
 
    # Calculate the sum of distances with mean for every element
    somme_dist_moyenne = 0
    for i in range(len(list)):
        somme_dist_moyenne+= (list[i]-m)**2

    # Variance = Sum of distances from mean/ Number of elements
    var = somme_dist_moyenne/len(list)

    return m,var

def ex8_periodique(list):
    """
    Returns period of signal if periodic
    """

    #Checking half the points of signal
    n = int(len(list)/2)
    # Empty list used 
    m = []
    
    # Traverse list 
    for i in range (3, n, 2):
        # Set temp list
        m = list[:i]

        # If list is equal to inverse (symmetric)
        if m == m[::-1]:

	    # Return list length (periodicity)
            return len(m)-1
        
    return 0    

def ex9_trouver_pulsT(list):

    """
    Returns cosinus deconstraction of periodic signal
    """

    # For first period
    for T1 in range (10, 101):

        # Calculate phase 
        w1 = (2 * math.pi) / T1

        # For second period 
        for T2 in range(10, 101):

            # Calculate phase
            w2 = (2 * math.pi) / T2
            f = []

            # For every element in list 
            for i in range (0,len(list)):
                # Calculate frequencies
                f.append(round(math.cos(w1*i) + math.cos(w2*i), 3))

            if f == list:
                return round(w1, 3), round(w2, 3)

             

if __name__ == "__main__":
    """
    TD 1 main function
    """

    # Read input
    list = ex1_lire_data("./data.txt")

    # Print n first values
    ex2_afficher_n_val(list,10)

    # Save n values to file
    ex3_stocker_n_au_fichier(list,10)
    print()

    # Print funtion maximum
    print("Maximum: ", ex4_maximum(list))
    print()
    
    # Print local maximums
    ex5_maximum_locaux(list)

    # Print Euclidean norm
    print("Norme Euclidienne : {:.3f}".format(ex6_norme_euclidienne(list)))
    print()

    # Print Mean and Variance
    moy, var = ex7_moyenne_et_variance(list)
    print("Moyenne: {:.3f} , Variance: {:.3f} ".format(moy,var))
    print()

    period = ex8_periodique(list)
    if period > 0:
        print("\nLa fonction est {}−periodique".format( period ))
    else:
        print("\nLa fonction n’est pas periodique")


    (pulsT1, pulsT2) = ex9_trouver_pulsT(list)
    print("\nLa fonction est somme de deux fonctions cosinus de pulsation {} et {}".format( pulsT1 , pulsT2 ))