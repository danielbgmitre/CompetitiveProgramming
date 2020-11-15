# -*- coding: utf-8 -*-

def solve(n: int, k: int) -> int:
    lo = 0
    hi = 10000000000
    last = 0
    while lo <= hi:
        mid = (lo + hi) // 2
        if (mid - (mid // n)) < k:
            lo = mid + 1
            last = mid
        else:
            hi = mid - 1
    return last + 1


for _ in range(int(input())):
    n, k = map(int, input().split())
    print(solve(n, k))
