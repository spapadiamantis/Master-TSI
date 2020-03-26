billets = [500, 200 , 100, 50 , 20, 10, 5, 2, 1]

somme = int(input("Donnez le somme "))

for i in billets:
	print('{}*{}'.format(somme//i,i),end='+')
	somme = somme -(somme//i)*i

print('\n')