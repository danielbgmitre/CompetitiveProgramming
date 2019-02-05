/*
 * Highway Decommission
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2910
 * Dijkstra solution
 */

#include <bits/stdc++.h>

using namespace std;

const long long INF = 999999999999LL;
const int MAXN = 10101;

struct node {
    int to;
    long long int len, cost;
    node() : to(0), len(INF), cost(INF) {}
    node(int _to, long long _len, long long _cost) : to(_to), len(_len), cost(_cost) {}

    // inverse comparator because priority_queue is a max_heap
    bool operator < (const node& other) const {
        if (len == other.len) {
            return cost > other.cost;
        }
        return len > other.len;
    }
};

bool lessThan(const node& a, const node& b) {
    if (a < b) return false;    // b is smaller
    return true;   // a is smaller
}


vector<node> adj[MAXN];

node dijkstra[MAXN];

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);

    int a, b;
    long long len, cost;
    for (int i=0; i<M; i++) {
        scanf(" %d %d %lld %lld", &a, &b, &len, &cost);
        adj[a].push_back({b, len, cost});
        adj[b].push_back({a, len, cost});
    }

    priority_queue<node> fila;
    fila.push({1, 0, 0});

    dijkstra[1] = {1, 0, 0};

    while (!fila.empty()) {
        node curr = fila.top();
        fila.pop();

        if (lessThan(curr, dijkstra[curr.to])) {
            for (node& next : adj[curr.to]) {
                node curr_cost(next.to, curr.len + next.len, next.cost);
                if (lessThan(curr_cost, dijkstra[next.to])) {
                    dijkstra[next.to] = curr_cost;
                    fila.push(curr_cost);
                }
            }
        }
    }

    long long res = 0LL;
    for (int i=1; i<=N; i++) {
        if (dijkstra[i].cost != INF) {
            res += dijkstra[i].cost;
        }
    }
    printf("%lld\n", res);

    return 0;
}
