#coding: utf-8

def solve(curr, path, remain):
    if len(remain) == 0:
        return path

    double = curr*2
    third = -1
    if curr%3 == 0:
        third = curr//3

    if (double not in remain) and (third not in remain):
        return []

    res = []

    if double in remain:
        res = solve(double, path+[double], remain-set([double]))

    if (res == []) and (third in remain):
        res = solve(third, path+[third], remain-set([third]))

    return res


N = int(raw_input())
numbers = set(map(int, raw_input().split()))

for n in numbers:
    res = solve(n, [n], numbers-set([n]))
    if res != []:
        print " ".join(map(str, res))
        break
