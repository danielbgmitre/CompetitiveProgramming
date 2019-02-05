/**
 * https://codeforces.com/problemset/problem/459/D
 * Pashmak and Parmida's problem
 * SQRT decomposition solution.
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 1000;
const int SQRT = sqrt(MAXN);

int a[MAXN], leftAcum[MAXN], rightAcum[MAXN], freq[MAXN];
long long units[MAXN], blocks[SQRT];

void remapNumbers(int N) {
    map<int, int> remapper;

    for (int i = 1; i <= N; i++) {
        if (!remapper.count(a[i])) {
            remapper[a[i]] = remapper.size();
        }
    }

    for (int i = 1; i <= N; i++) {
        a[i] = remapper[a[i]];
    }
}

void insert(int idx) {
    units[idx]++, blocks[idx/SQRT]++;
}

long long get(int l, int r) {
    long long res = 0;
    while (l <= r) {
        if ((l % SQRT == 0) && (l + SQRT <= r)) {
            res += blocks[l/SQRT];
            l += SQRT;
        } else {
            res += units[l];
            l += 1;
        }
    }
    return res;
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i = 1; i <= N; i++) {
        scanf(" %d", &a[i]);
    }

    remapNumbers(N);

    for (int i = 1; i <= N; i++) {
        leftAcum[i] = ++freq[a[i]];
    }

    memset(freq, 0, sizeof freq);

    for (int i = N; i >= 1; i--) {
        rightAcum[i] = ++freq[a[i]];
    }

    long long int res = 0;
    for (int i = N; i >= 1; i--) {
        res += get(1, leftAcum[i] - 1);
        insert(rightAcum[i]);
    }

    printf("%lld\n", res);

    return 0;
}
