# @author Thúlio C.

flags = [0, 2]
N = int(raw_input())
for i in xrange(2, N+1):
    flags.append(flags[i-1] + flags[i-2])
print flags[N]
