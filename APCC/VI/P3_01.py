# @author Thúlio C.

n = int(raw_input())
heaps = map(int, raw_input().split())
result = 0
for i in heaps:
    if i >= 3:
        x = i / 2
        result += x
if result % 2 == 0: print 'Stannis'
else: print 'Daenerys'
