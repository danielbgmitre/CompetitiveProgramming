//http://www.spoj.com/problems/LCA/
//LCA - Lowest Common Ancestor

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int LOGN = (log(MAXN)/log(2))+1;

int RMQ[MAXN][LOGN], level[MAXN];
vector<int> tree[MAXN];

int LCA(int a, int b){
    if (level[b] < level[a]){
        swap(a, b);
    }

    for (int l=LOGN-1; l>=0; l--){
        if (level[a] <= level[RMQ[b][l]]){
            b = RMQ[b][l];
        }
    }

    assert(level[a] == level[b]);

    if (a == b) return a;

    for (int l=LOGN-1; l>=0; l--){
        if (RMQ[a][l] != RMQ[b][l]){
            a = RMQ[a][l];
            b = RMQ[b][l];
        }
    }

    return RMQ[a][0];
}

void zera(int N){
    for (int i=0; i <= N; i++){
        level[i] = 0;
        for (int j=0; j < LOGN; j++){
            RMQ[i][j] = 1;
        }
    }
}

int main(){
    int T;
    scanf(" %d", &T);
    for (int t=1; t<=T; t++){
        int N, M, node;
        scanf(" %d", &N);
        zera(N);

        for (int i=1; i<=N; i++){
            scanf(" %d", &M);
            tree[i].reserve(M);
            for (int m=0; m<M; m++){
                scanf(" %d", &node);
                tree[i].push_back(node);
                RMQ[node][0] = i;
                level[node] = level[i]+1;
            }
        }

        for (int i=1; i<=N; i++){
            for (int j=1; j<LOGN; j++){
                RMQ[i][j] = RMQ[RMQ[i][j-1]][j-1];
            }
        }

        //setLevel(1);

        int Q, a, b;
        scanf(" %d", &Q);
        printf("Case %d:\n", t);
        for (int q=0; q<Q; q++){
            scanf(" %d %d", &a, &b);
            printf("%d\n", LCA(a, b));
        }

    }

}
