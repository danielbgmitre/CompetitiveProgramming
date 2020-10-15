# -*- coding: utf-8 -*-

def backtrack(numbers: list, bit: int, k: int, remaining: list):
    if (bit < 0):
        res = -1
        for n in remaining:
            res &= n
        return res

    next_remaining = list(filter(lambda n: (1 << bit) & n, remaining))

    if len(next_remaining) >= k:
        return backtrack(numbers, bit - 1, k, next_remaining)

    return backtrack(numbers, bit - 1, k, remaining)


for _ in range(int(input())):
    N, K = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(backtrack(numbers, 31, K, numbers))
