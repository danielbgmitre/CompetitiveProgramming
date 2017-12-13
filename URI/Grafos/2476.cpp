//https://www.urionlinejudge.com.br/judge/pt/problems/view/2476
//Entregas do Noel

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int LOGN = (log(MAXN)/log(2)) + 1;

map<string, int> comp;
int tree[MAXN], level[MAXN], rmq[MAXN][LOGN];
vector<int> adj[MAXN];

void bfs(int start){
    queue<int> fila;
    fila.push(start);
    level[start] = 0;

    while (!fila.empty()){
        int topo = fila.front(); fila.pop();
        //set<int> &top_set = uniques[topo];

        for (int next : adj[topo]){
            level[next] = level[topo] + 1;
            fila.push(next);
        }
    }
}

void build(int N){
    bfs(1);

    for (int j=1; j<LOGN; j++){
        for (int i=1; i<=N; i++){
            rmq[i][j] = rmq[rmq[i][j-1]][j-1];
        }
    }
}

int lca(int a, int b){
    if (level[b] < level[a]){
        swap(a, b);
    }

    for (int l = LOGN-1; l>=0; l--){
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

int main(){
    int N, M;
    scanf(" %d %d", &N, &M);

    char temp[100];
    for (int i=1; i<=N; i++){
        scanf(" %s", temp);
        if (comp.count(temp) == 0){
            comp[temp] = comp.size();
        }
        tree[i] = comp[temp];
    }

    int a, b;
    for (int i=1; i<N; i++){
        scanf(" %d %d", &a, &b);
        rmq[b][0] = a;
        adj[a].push_back(b);
    }

    build(N);

    set<int> res;
    for (int i=0; i<M; i++){
        scanf(" %d %d", &a, &b);

        int _lca = lca(a, b);

        res.insert(tree[_lca]);

        while (a != _lca){
            res.insert(tree[a]);
            a = rmq[a][0];
        }
        while (b != _lca){
            res.insert(tree[b]);
            b = rmq[b][0];
        }

        printf("%d\n", res.size());
        res.clear();
    }


    return 0;
}
