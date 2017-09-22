#coding: utf-8

par = impar = pos = neg = 0

for i in range(5):
    n = int(raw_input())
    if n % 2:
        impar += 1
    else:
        par += 1

    if n > 0:
        pos += 1

    if n < 0:
        neg += 1

print("%d valor(es) par(es)" %par)
print("%d valor(es) impar(es)" %impar)
print("%d valor(es) positivo(s)" %pos)
print("%d valor(es) negativo(s)" %neg)
        
