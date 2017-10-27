//https://www.urionlinejudge.com.br/judge/pt/problems/view/1135
//Colonia de Formigas

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int LOGN = 20;

typedef long long int ll;

int parent[MAXN], level[MAXN], rmq[MAXN][LOGN];
ll weight[MAXN], dist[MAXN];

void zera(int N){
    for (int i=0; i<N; i++){
        parent[i] = weight[i] = level[i] = 0;
        dist[i] = -1;
        for (int j=0; j<LOGN; j++){
            rmq[i][j] = 0;
        }
    }
}

void dfs(int i){
    if (dist[parent[i]] == -1){
        dfs(parent[i]);
    }
    dist[i]  = dist[parent[i]] + weight[i];
    level[i] = level[parent[i]] + 1;
}

void calcula(int N){
    dist[0] = 0;
    level[0] = 0;

    for (int i=1; i<N; i++){
        dfs(i);
    }

    for (int j=0; j<LOGN; j++){
        for (int i=0; i<N; i++){
            if (j == 0) {
                rmq[i][j] = parent[i];
            } else {
                rmq[i][j] = rmq[rmq[i][j-1]][j-1];
            }
        }
    }
}

int lca(int a, int b){
    if (level[a] > level[b]) swap(a, b);
    //assert(level[b] >= level[a]);
    for (int i=LOGN-1; i>=0; i--){
        if (level[rmq[b][i]] >= level[a]){
            b = rmq[b][i];
        }
    }

    if (a == b) return a;
    //assert(level[a] == level[b]);
    for (int i=LOGN-1; i>=0; i--){
        if (rmq[a][i] != rmq[b][i]){
            a = rmq[a][i];
            b = rmq[b][i];
        }
    }
    return parent[a];
}

int main(){
    int N;
    while (scanf(" %d", &N) && N != 0){
        zera(N);
        for (int i=1; i<N; i++){
            scanf(" %d %lld", &parent[i], &weight[i]);
        }
        calcula(N);

        int Q, a, b; scanf(" %d", &Q);
        while (Q--){
            scanf(" %d %d", &a, &b);
            printf("%lld", ((dist[a] + dist[b]) - 2 * dist[lca(a, b)]));
            if (Q){
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}
