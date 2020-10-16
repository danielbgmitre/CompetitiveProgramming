# -*- coding: utf-8 -*-

def backtrack(numbers: list, bit: int, k: int, remaining: list):
    if len(remaining) < k:
        return -1

    if (bit < 0):
        res = -1
        for n in remaining:
            res &= n
        return res

    next_remaining = list(filter(lambda n: (1 << bit) & n, remaining))

    if (res := backtrack(numbers, bit - 1, k, next_remaining)) >= 0:
        return res

    return backtrack(numbers, bit - 1, k, remaining)


for _ in range(int(input())):
    N, K = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(backtrack(numbers, 31, K, numbers))
