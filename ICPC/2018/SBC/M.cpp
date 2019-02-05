/*
 * Mount Marathon
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2915
 * O(n) solution
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;

int card[MAXN];

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i < N; i++) {
        scanf(" %d", &card[i]);
    }

    int piles = N;

    for (int i=0; i + 1 < N; i++) {
        if (card[i] >= card[i + 1]) {
            piles--;
        }
    }

    printf("%d\n", piles);

    return 0;
}
