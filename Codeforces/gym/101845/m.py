#coding: utf-8


# cunfused M and N order
M, N, K = map(int, raw_input().split())

prob = 0.0

if (K <= N):   # fill K-1 with blue
    N -= K-1
    prob = (K-1)
    prob += float(N) / float(N+M)
else:
    prob = float(N)
    N = 0
    M -= (K - N) - 1

prob /= float(K)

print "%.15f" % prob
