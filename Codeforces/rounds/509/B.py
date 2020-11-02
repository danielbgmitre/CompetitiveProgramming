# -*- coding: utf-8 -*-

n, colors = map(int, input().split())
piles = list(map(int, input().split()))

min_size = min(piles)
max_size = max(piles)

if max_size > (min_size + colors):
    print('NO')
else:
    print('YES')
    for pile in piles:
        color1 = min(pile, min_size + 1)
        pile_colors = ['1' for _ in range(color1)]
        pile_colors.extend([str(idx)
                            for idx, _ in enumerate(range(color1, pile), start=2)])
        print(' '.join(pile_colors))
