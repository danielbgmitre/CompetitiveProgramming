import sys
from os import system

prob = sys.argv[1]

system("g++ {0}.cpp -o {0}".format(prob))

if len(sys.argv) == 4:
    system("./{0} < {1} > {2}".format(prob, sys.argv[2], sys.argv[3]))
elif len(sys.argv) == 3:
    system("./{0} < {1}".format(prob, sys.argv[2]))
else:
    system("./{0}".format(prob))
