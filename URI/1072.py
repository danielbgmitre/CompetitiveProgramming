#coding: utf-8

countIn = countOut = n = 0

for i in range(int(raw_input())):
    n = int(raw_input())
    if (n >= 10 and n <= 20):
        countIn += 1
    else:
        countOut += 1

print "%d in\n%d out" %(countIn, countOut)
