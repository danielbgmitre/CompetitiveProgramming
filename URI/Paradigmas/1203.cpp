#include <bits/stdc++.h>

using namespace std;

const int MAXR = 111;
const int MAXK = (MAXR*MAXR)/2;


int qtd[MAXR];
int dp[MAXK];

void limpa(){
    for (int i=0; i<MAXR; i++) {
        qtd[i] = 0;
    }
    for (int i=0; i<MAXK; i++) {
        dp[i] = 0;
    }
}

int main() {
    int R, K;
    while (scanf(" %d %d", &R, &K) != EOF) {
        limpa();

        int a, b;
        for (int i=0; i<K; i++) {
            scanf(" %d %d", &a, &b);
            qtd[a-1]++; qtd[b-1]++;
        }


        dp[0] = 1;
        for (int i=0; i<R; i++) {
            for (int j=K; j-qtd[i] >= 0; j--) {
                dp[j] = max(dp[j], dp[j-qtd[i]]);
            }
        }

        printf((dp[K])? "S\n" : "N\n");
    }

    return 0;
}
