#coding: utf-8

def multiply_range(n, m):
    #print n, m
    if n == m:
        return n
    if m < n:
        return 1
    else:
        return multiply_range(n, (n+m)/2) * multiply_range(((n+m)/2)+1, m)
    
def my_factorial(n):
    if n == 0:
        return 1
    return multiply_range(1, n)


alfabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

while 1:
    entrada = ''
    freq = [0 for i in alfabet]
    try:
        entrada = raw_input()        
    except:
        break

    poss = my_factorial(len(entrada))
    for i in entrada:
        freq[ord(i)-ord('A')] += 1

    for i in freq:
        poss = poss/my_factorial(i)

    print poss % 1000000007
    
    
