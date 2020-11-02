# -*- coding: utf-8 -*-

_ = input()
nums = sorted(map(int, input().split()), reverse=True)
half = sum(nums) // 2
acum = 0
for coin, num in enumerate(nums, start=1):
    acum += num
    if acum > half:
        print(coin)
        break
