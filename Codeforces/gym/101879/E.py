#coding: utf-8

fat = [1 for _ in range(31)]

for i in range(1, len(fat)):
    fat[i] = i * fat[i-1]

def comb(n, p):
    return fat[n]/(fat[n-p] * fat[p])

N = int(raw_input())

solution = 0

for i in range(2, N+1):
    solution += comb(N, i)

print solution
