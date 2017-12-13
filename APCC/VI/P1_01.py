# @author Thúlio C.

N = int(raw_input())
val = []
x = 0
while x < N:
    val.append(map(int, raw_input().split()))
    x += 1
val = sorted(val, key=lambda x: x[1], reverse=True)
for i in val: print "%d %d" % (i[0], i[1])
