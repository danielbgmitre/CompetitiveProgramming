# -*- coding: utf-8 -*-

def brute(word: str, solutions: dict):
    for ch in word:
        for key in list(solutions.keys()):
            solutions[key + ch] = 1
        solutions[ch] = 1


try:
    while 1:
        sol = {}
        brute(input(), sol)
        print('\n'.join(sorted(sol.keys())))
        print()
except:
    pass
