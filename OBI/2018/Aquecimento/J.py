#coding: utf-8

import sys

def dr(num):
    num = str(num)
    s = num
    while len(s) > 1:
        soma = 0
        for i in xrange(len(s)):
            soma = soma + int(s[i])
        s = str(soma)
    return int(s)

def pdr(x, y):
    pos = y%6
    if (x == 1):
        return 1

    if (x == 2):
        return [1,2,4,8,7,5][pos];
    if (x == 3):
        if (y==1):
            return 3
        return 9
    if (x == 4):
        return [1,4,7][pos%3]
    if ()
    #TODO

b = raw_input()
e = int(raw_input())

print pdr(b, e)
