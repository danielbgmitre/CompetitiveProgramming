#coding: utf-8

def solve(n):
    tam, div = 1, 2
    res = 0
    while div <= n:
        res += (div / 2) * tam * (n / div)
        div *= 2
        tam +=1

    return res

n = int(raw_input())
for _ in xrange(n):
    print(solve(int(raw_input())))
