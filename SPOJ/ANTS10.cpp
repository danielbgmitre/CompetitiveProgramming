//http://br.spoj.com/problems/ANTS10/
//ANTS10 - Colônia de Formigas

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

const int MAXN = 2e5 + 10;
const int LOGN = (log(MAXN)/log(2)) + 1;

int rmq[MAXN][LOGN], level[MAXN], parent[MAXN];
long long int dist[MAXN];
vector<int> childs[MAXN];

void setLevel(){
    queue<int> fila;
    fila.push(0);
    level[0] = 0;
    dist[0] = 0;

    while (!fila.empty()){
        int front = fila.front(); fila.pop();
        for (int child : childs[front]){
            level[child] = level[front] + 1;
            dist[child] = dist[front] + dist[child];
            fila.push(child);
        }
    }
}


int lca(int a, int b){
    if (level[b] < level[a]){
        swap(a, b);
    }

    for (int l=LOGN-1; l>=0; l--){
        if (level[a] <= level[rmq[b][l]]){
            b = rmq[b][l];
        }
    }

    assert(level[a] == level[b]);

    if (a == b) return a;

    for (int l=LOGN-1; l>=0; l--){
        if (rmq[a][l] != rmq[b][l]){
            a = rmq[a][l];
            b = rmq[b][l];
        }
    }

    return rmq[a][0];
}

void zera(int N){
    for (int i=0; i<=N; i++){
        dist[i] = parent[i] = level[i] = 0;
        childs[i].clear();
        for (int l=0; l < LOGN; l++){
            rmq[i][l] = 0;
        }
    }
}

int main(){
    int N;
    while (scanf(" %d", &N) && N){
        zera(N);

        for (int i=1; i<N; i++){
            scanf(" %d %lld", &parent[i], &dist[i]);
            rmq[i][0] = parent[i];
            childs[parent[i]].push_back({i});
        }

        for (int l=1; l<LOGN; l++){
            for (int i=1; i<=N; i++){
                rmq[i][l] = rmq[rmq[i][l-1]][l-1];
            }
        }

        setLevel();

        int Q;
        scanf(" %d", &Q);

        int arg1, arg2;
        while (Q--){
            scanf(" %d %d", &arg1, &arg2);
            printf("%lld", dist[arg1] + dist[arg2] - 2*dist[lca(arg1, arg2)]);
            printf(Q? " " : "\n");
        }
    }



    return 0;
}
