# -*- coding: utf-8 -*-

def lex_sort(a: str) -> str:
    if len(a) % 2:
        return a

    half = len(a) // 2
    left = lex_sort(a[:half])
    right = lex_sort(a[half:])

    if left < right:
        return left + right
    return right + left


a = input()
b = input()
if lex_sort(a) == lex_sort(b):
    print('YES')
else:
    print('NO')
