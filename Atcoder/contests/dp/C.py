# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(1000000)

n = int(input())

gain = [list(map(int, input().split())) for _ in range(n)]

for i in range(n-2, -1, -1):
    for activity in range(3):
        g = gain[i][activity]
        gain[i][activity] = 0

        for j in range(3):
            if j != activity:
                gain[i][activity] = max(gain[i][activity], gain[i+1][j])
        gain[i][activity] += g

print(max(gain[0]))
