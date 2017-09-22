x = int(raw_input())
y = int(raw_input())

if (y < x): x, y = y, x

res = 0
for i in range(x+1, y):
    if (i%2): res += i 
print res
