//https://www.urionlinejudge.com.br/judge/pt/problems/view/1476
//Caminhão

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
const int LOGN = (log(MAXN)/log(2)) + 1;

struct ponte{
    int from;
    int to;
    int peso;
    ponte(){
        from = to = peso = 0;
    }
    ponte(int a, int b, int p){
        from = a;
        to = b;
        peso = p;
    }
};

vector<ponte> pontes, adj[MAXN*2];
int woods_rank[MAXN], woods[MAXN], level[MAXN], lca[MAXN][LOGN], peso[MAXN][LOGN];
bool visited[MAXN];

bool cmp(ponte a, ponte b){
    return a.peso > b.peso;
}

int component(int a){
    if (woods[a] == a){
        return a;
    }
    woods[a] = component(woods[a]);
    return woods[a];
}

void join(int a, int b){
    if (woods_rank[woods[a]] < woods_rank[woods[b]]){
        swap(a, b);
    }
    woods_rank[component(a)] += woods_rank[component(b)];
    woods_rank[component(b)] = 0;
    woods[component(b)] = component(a);
}

void mst(int N, int tam){
    sort(pontes.begin(), pontes.end(), cmp);
    int total = 0;
    for (ponte p : pontes){
        if (component(p.from) != component(p.to)){
            total++;
            adj[p.from].push_back(p);
            adj[p.to].push_back({p.to, p.from, p.peso});
            join(p.from, p.to);
        }
    }
    assert(total == N-1);
}

void bfs(int root, int N){
    queue<int> fila;
    fila.push(root);
    visited[root] = true;
    level[root] = 0;

    int vertice;
    while (!fila.empty()){
        vertice = fila.front(); fila.pop();
        for (ponte p : adj[vertice]){
            if (!visited[p.to]){
                level[p.to] = level[vertice]+1;
                lca[p.to][0] = vertice;
                peso[p.to][0] = p.peso;
                fila.push(p.to);
                visited[p.to] = true;
            }
        }
    }

}

void build(int N){
    bfs(1, N);

    for (int j=1; j<LOGN; j++){
        for (int i=0; i<=N; i++){
            lca[i][j] = lca[lca[i][j-1]][j-1];
            peso[i][j] = min(peso[i][j-1], peso[lca[i][j-1]][j-1]);
        }
    }
}

void zera(int N){
    for (int i=0; i<=N; i++) {
        for (int j=0; j<LOGN; j++){
            lca[i][j] = 1;
            peso[i][j] = 999999999;
        }
        woods[i] = i;
        woods_rank[i] = 1;
        pontes.clear();
        adj[i*2].clear();
        adj[i*2+1].clear();
        visited[i] = false;
    }
}

int query(int a, int b){
    if (level[b] < level[a]){
        swap(a, b);
    }
    int maximo = 999999999;

    for (int i=LOGN-1; i>=0; i--){
        if (level[lca[b][i]] >= level[a]){
            maximo = min(maximo, peso[b][i]);
            b = lca[b][i];
        }
    }

    assert(level[a] == level[b]);
    if (a == b) return maximo;

    for (int i=LOGN-1; i>=0; i--){
        if (lca[a][i] != lca[b][i]){
            maximo = min(maximo, peso[a][i]);
            maximo = min(maximo, peso[b][i]);
            a = lca[a][i];
            b = lca[b][i];
        }
    }

    maximo = min(maximo, peso[a][0]);
    maximo = min(maximo, peso[b][0]);

    return maximo;
}

int main(){
    int N, M, S;
    while (scanf(" %d %d %d", &N, &M, &S) != EOF){
        zera(N);

        int a, b, p;
        for (int i=0; i<M; i++){
            scanf(" %d %d %d", &a, &b, &p);
            pontes.push_back({a, b, p});
        }

        mst(N, M);
        build(N);

        for (int i=0; i<S; i++){
            scanf(" %d %d", &a, &b);
            printf("%d\n", query(a, b));
        }
    }

    return 0;
}
