# -*- coding: utf-8 -*-

inversions = 0


def merge(arr1, arr2):
    global inversions
    mid = len(arr1)
    sz = len(arr1) + len(arr2)
    merged = [0 for _ in range(sz)]

    arr1.append(float('inf'))
    arr2.append(float('inf'))

    i = 0
    j = 0
    for idx in range(sz):
        if arr1[i] <= arr2[j]:
            merged[idx] = arr1[i]
            i += 1
        else:
            merged[idx] = arr2[j]
            j += 1
            inversions += mid - i
    return merged


def mergesort(arr):
    if len(arr) == 1:
        return arr

    mid = len(arr) // 2
    left = mergesort(arr[:mid])
    right = mergesort(arr[mid:])
    return merge(left, right)


n = int(input())
while n > 0:
    arr = list(map(int, input().split()))
    inversions = 0
    mergesort(arr)
    print(inversions)
    n = int(input())
