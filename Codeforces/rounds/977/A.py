#coding: utf-8

N, K = raw_input().split()
K = int(K)

for i in range(K):
    if (len(N) > 0):
        if (N[-1] == '0'):
            N = N[:-1]
        else:
            N = N[:-1] + str(int(N[-1])-1)

print N
