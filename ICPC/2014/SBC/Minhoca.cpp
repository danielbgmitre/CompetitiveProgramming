#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

typedef pair<int, int> pii;

const int MAXS = 1e4 + 10;
const int INF = 0x3f3f3f3f;

vector<int> adj[MAXS];
vector<int> pesos[MAXS];

int parent[MAXS];
int dist[MAXS], real_dist[MAXS];
bitset<MAXS> visited;

void dfs_aux(int pos, int minhoca, int &res) {
    visited[pos] = 1;

    for (size_t i=0; i<adj[pos].size(); i++) {
        int next = adj[pos][i];
        int tam = pesos[pos][i];

        if (next == parent[pos]) continue;

        if (!visited[next]) {
            parent[next] = pos;
            real_dist[next] = real_dist[pos] + tam;
            dfs_aux(next, minhoca, res);
        }

        if (visited[next] && tam + real_dist[pos] - real_dist[next] >= minhoca) {
            res = min(res, tam + real_dist[pos] - real_dist[next] + 2 * dist[next]);
        }
    }
}

int dfs(int start, int minhoca, int size) {
    for (int i=0; i<=size; i++) {
        real_dist[i] = INF;
        parent[i] = 0;
    }
    visited.reset();
    int res = INF;
    dfs_aux(start, minhoca, res);
    return res;
}

void dijkstra(int start, int size) {
    for (int i=0; i<=size; i++) {
        dist[i] = INF;
    }

    queue<pii> fila;
    fila.push({0, start});
    dist[start] = 0;

    while (!fila.empty()) {
        int curr_dist = fila.front().st;
        int pos = fila.front().nd;
        fila.pop();

        if (curr_dist > dist[pos]) continue;

        for (size_t idx=0; idx<adj[pos].size(); idx++) {
            int next = adj[pos][idx];
            int tam = pesos[pos][idx];

            if (dist[pos] + tam < dist[next]) {
                dist[next] = dist[pos]+tam;
                fila.push({dist[next], next});
            }
        }
    }

}

int main() {
    int S, T;
    while (~scanf(" %d %d", &S, &T)) {
        int A, B, C;
        for (int i=0; i<T; i++) {
            scanf(" %d %d %d", &A, &B, &C);
            adj[A].push_back(B);
            pesos[A].push_back(C);
            adj[B].push_back(A);
            pesos[B].push_back(C);
        }

        int Q;
        scanf(" %d", &Q);

        while (Q--) {
            int X, M;
            scanf(" %d %d", &X, &M);

            dijkstra(X, S);
            int minimum = dfs(X, M, S);

            if (minimum == INF) minimum = -1;

            printf("%d\n", minimum);
        }
    }

    return 0;
}
