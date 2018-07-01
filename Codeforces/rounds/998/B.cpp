#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;

int numb[MAXN], par[MAXN], impar[MAXN];

int impares(int start, int end) {
    return impar[end]-impar[start-1];
}

int pares(int start, int end) {
    return par[end]-par[start-1];
}

int main() {
    int N, B;
    scanf(" %d %d", &N, &B);

    for (int i=1; i<=N; i++) {
        scanf(" %d", &numb[i]);
        par[i] = par[i-1] + !(numb[i]&1);
        impar[i] = impar[i-1] + (numb[i]&1);
    }

    int total = 0;
    int cuts=0;
    bool possible = true;

    bitset<MAXN> cuted;
    while (possible) {
        int best = -1;
        int idx=0;
        for (int i=1; i<N; i++) {
            if (impares(1, i) == pares(1, i)) {
                if (!cuted[i] && (best == -1 || abs(numb[i+1]-numb[i]) < best)) {
                    best = abs(numb[i+1]-numb[i]);
                    idx = i;
                }
            }
        }
        if (best == -1 || total + best > B) {
            possible = false;
        } else {
            total += best;
            cuts++;
            cuted[idx] = true;
        }
    }

    printf("%d\n", cuts);

    return 0;
}
