# @author Thúlio C.

from math import *

def distPontos(b, a):
    Xa, Ya = a[0], a[1] 
    Xb, Yb = b[0], b[1]
    return (sqrt(((Xa-Xb)**2) + (Ya-Yb)**2))
n, r = map(float, raw_input().split())
pontos = []
result = 0
n = int(n)
for x in xrange(n):
    newPonto = map(float, raw_input().split())
    pontos.append(newPonto)
if n % 2 == 0:
    for i in xrange(1, len(pontos)):
        result += distPontos(pontos[i], pontos[i-1])
        
else:
    for i in xrange(0, len(pontos)-1):
        result += distPontos(pontos[i+1], pontos[i])
result += distPontos(pontos[n-1], pontos[0])
result += 2*pi*r
print '%.2f' % result
