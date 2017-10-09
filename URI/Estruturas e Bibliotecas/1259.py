#coding: utf-8
#https://www.urionlinejudge.com.br/judge/pt/problems/view/1259
#Pares e Ímpares

N = int(raw_input())

pares = []
impares = []

for i in xrange(N):
    temp = int(raw_input())
    if temp % 2:
        impares.append(temp)
    else:
        pares.append(temp)

pares.sort()
impares.sort()

for number in pares:
    print number

for i in xrange(len(impares)-1, -1, -1):
    print impares[i]
