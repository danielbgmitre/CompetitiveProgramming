# -*- coding: utf-8 -*-

def reachable(matrix, curr: tuple, end: tuple) -> bool:
    x, y = curr

    # checa validade
    if (x < 0) or (x > 4) or (y < 0) or (y > 4) or matrix[x][y]:
        return False

    if curr == end:  # condicao de parada
        return True

    prev = matrix[x][y]
    matrix[x][y] = True

    res = False
    for dX, dY in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        res = res or reachable(matrix, (x + dX, y + dY), end)

    matrix[x][y] = prev
    return res


T = int(input())
for _ in range(T):
    matrix = []
    while len(matrix) < 5:
        line = list(map(int, input().split()))
        if len(line) > 0:  # uri testcases are "dirty" with some empty lines
            matrix.append(line)

    if reachable(matrix, (0, 0), (4, 4)):
        print('COPS')
    else:
        print('ROBBERS')
