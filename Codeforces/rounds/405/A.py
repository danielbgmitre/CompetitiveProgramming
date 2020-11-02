# -*- coding: utf-8 -*-

_ = input()
nums = list(map(int, input().split()))
print(str(' '.join(map(str, sorted(nums)))))
