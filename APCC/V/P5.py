#coding: utf-8
#https://www.urionlinejudge.com.br/judge/pt/problems/view/2018
#Olimpiadas de Natal

def compare(a, b):
	if (a[0] == b[0]):
		if a[1] < b[1]:
			return 1
		else:
			return -1
	else:
		if a[0] > b[0]:
			return 1
		else:
			return -1

res = {}

while 1:
	entrada = ''
	try:
		entrada = raw_input()
		for i in range(3):
			pais = raw_input()
			if pais not in res:
				res[pais] = [0, 0, 0]
			res[pais][i] += 1;

	except:
		break

ordenado = []
for pais in res:
	ordenado.append([res[pais], pais])

ordenado = sorted(ordenado, cmp=compare)

print "Quadro de Medalhas"

for pais in ordenado[::-1]:
	print pais[1], pais[0][0], pais[0][1], pais[0][2]
