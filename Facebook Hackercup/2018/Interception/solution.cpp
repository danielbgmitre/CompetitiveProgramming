#include <bits/stdc++.h>

using namespace std;

const int MAXN = 54;

int main() {
    int T;
    scanf(" %d", &T);

    for (int t=1; t<=T; t++) {
        int N;
        scanf(" %d", &N);

        int polinomy[MAXN];
        for (int i=0; i <= N; i++) {
            scanf(" %d", &polinomy[i]);
            polinomy[i+1] = 0;
        }

        int i=0;
        int grau = N;
        for (; (i <= N) && (grau+polinomy[i+1] != 0); i++) {
            grau--;
        }
        printf("Case #%d:", t);
        if (i&1) {
            printf(" 1\n0.0\n");
        } else {
            printf(" 0\n");
        }
    }

    return 0;
}
