# -*- coding: utf-8 -*-

def backtrack(numbers: list, idx: int, best: int, curr: int, remaining: int) -> int:
    if idx == len(numbers):
        if remaining > 0:
            return float('-inf')
        return curr

    if (curr > -1) and (curr <= best):
        print("%d <= %d" % (curr, best))
        return curr

    if remaining > 0:
        best = max(best, backtrack(numbers, idx + 1, best,
                                   curr & numbers[idx], remaining - 1))

    return max(best, backtrack(numbers, idx + 1, best, curr, remaining))


for _ in range(int(input())):
    _, K = map(int, input().split())
    numbers = list(map(int, input().split()))
    print(backtrack(numbers, 0, -1, -1, K))
