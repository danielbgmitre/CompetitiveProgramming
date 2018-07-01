#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int MAXW = 5000;

struct Item {
    char nome[100];
    int peso;

    bool operator () (const Item& a, const Item& b){
        return a.peso > b.peso;
    }
};

Item itens[MAXN];
int dp[MAXN][MAXW];

void solve(int m){
    for (int i=1; i<=m; i++) {
        Item curr = itens[i-1];
        for (int j=0; j<MAXW; j++) {
            if (curr.peso > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(curr.peso+dp[i-1][j-curr.peso], dp[i-1][j]);
            }
        }
    }
}

int used_itens[MAXN];
int getItens(int m, int w){
    int qtd = 0;
    while (m > 0){
        if (dp[m][w] != dp[m-1][w]){
            used_itens[qtd++] = m-1;
            w -= itens[m-1].peso;
        }

        m--;
    }
    return qtd;
}

int main() {
    int kit, M;
    scanf(" %d %d", &kit, &M);

    for (int i=0; i<M; i++) {
        scanf(" %s %d", itens[i].nome, &itens[i].peso);
    }

    solve(M);

    int N;
    scanf(" %d", &N);

    int w;
    for (int i=0; i<N; i++){
        scanf(" %d", &w);
        w = (w+1)>>1;
        w -= kit;

        if (w <= 0) {
            printf("0\n");
            continue;
        } else if (w > dp[M][MAXW-1]){
            printf("-1\n");
        } else {
            while (dp[M][w] < w) w++;
            int qtd = getItens(M, w);
            printf("%d", qtd);
            for (int q=0; q<qtd; q++){
                printf(" %s", itens[used_itens[q]].nome);
            }
            printf("\n");
        }
    }

    return 0;
}
