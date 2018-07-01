#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

bitset<MAXN> visited;
vector<int> adj[MAXN];
bool cover[MAXN];

bool dfs(int v) {
    bool use = 0;
    for (int next : adj[v]) {
        if (!visited[next]){
            visited[next] = 1;
            use = dfs(next) || use;
        }
    }
    cover[v] = use;
    return !cover[v];
}

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);

    int a, b;
    for (int i=0; i<M; i++){
        scanf(" %d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited[1] = 1;
    dfs(1);

    int res = 0;

    for (int i=1; i<=N; i++){
        if (!cover[i]) res++;
    }

    printf("%d\n", res);

    return 0;
}
