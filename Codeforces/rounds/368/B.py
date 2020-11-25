# -*- coding: utf-8 -*-

n, m = map(int, input().split())

arr = list(map(int, input().split()))
ans = [0 for _ in range(n)]
cnt = [0 for _ in range(100100)]

curr = 0
for i in range(n - 1, -1, -1):
    cnt[arr[i]] += 1
    if cnt[arr[i]] == 1:
        curr += 1
    ans[i] = curr

for _ in range(m):
    print(ans[int(input()) - 1])
