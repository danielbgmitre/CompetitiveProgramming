#coding: utf-8

resultados = [(-1, -1) for _ in range(50)]

#(res, calls)
resultados[0] = (0, 1)
resultados[1] = (1, 1)

def fib(X):
    if (resultados[X] == (-1, -1)):
        resultados[X] = (fib(X-1)[0] + fib(X-2)[0], 1 + fib(X-1)[1] + fib(X-2)[1])
    return resultados[X]

N = int(raw_input())
for _ in range(N):
    X = int(raw_input())
    res = fib(X)
    print "fib({}) = {} calls = {}".format(X, res[1]-1, res[0])
