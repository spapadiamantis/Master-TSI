
s = 'Python est un langage très sympa'
voyelles = ['a', 'e', 'i', 'o', 'u', 'y', 'à', 'è', 'ù', 'â', 'ê', 'î', 'ô', 'û', 'é']
cnt=0
for i in range(0,len(s)):
	if s[i] in voyelles:
		cnt+=1

print(cnt)