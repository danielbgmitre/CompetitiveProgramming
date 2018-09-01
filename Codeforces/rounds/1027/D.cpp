#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 100;

int prox[MAXN];
int cost[MAXN];
int parent[MAXN];

bitset<MAXN> isOnCicle;
bitset<MAXN> visited;
long long soma = 0LL;

void dfs(int curr, int prev, int N) {
    visited[curr] = 1;
    isOnCicle[curr] = 1;
    parent[curr] = prev;

    int next = prox[curr];
    if (!isOnCicle[next]) {
        dfs(next, curr, N);
    } else if (visited[next]) {
        int menor = cost[next];
        int it = curr;
        while (it != next) {
            menor = min(menor, cost[it]);
            it = parent[it];
        }
        soma += menor;
    }

    visited[curr] = 0;
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=1; i<=N; i++) {
        scanf(" %d", &cost[i]);
    }

    for (int i=1; i<=N; i++) {
        scanf(" %d", &prox[i]);
    }

    for (int i=1; i<=N; i++) {
        if (!isOnCicle[i])
            dfs(i, 0, N);
    }
    printf("%lld\n", soma);

    return 0;
}
