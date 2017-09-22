#coding: utf-8

for i in xrange(int(raw_input())):
    n = int(raw_input())

    if n == 0:
        print "NULL"
        continue

    if n%2:
        if (n>0):
            print "ODD POSITIVE"
        else:
            print "ODD NEGATIVE"
    else:
        if (n>0):
            print "EVEN POSITIVE"
        else:
            print "EVEN NEGATIVE"
