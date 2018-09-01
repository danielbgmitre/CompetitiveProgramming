#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

vector<int> tree[MAXN];

int res = 1;

void dfs(int node, int parent, int total) {
    if (total > res) {
        res = total;
    }

    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node, total+1);
        }
    }
}

int main() {
    int N, start;
    scanf(" %d %d", &N, &start);

    int from, to;
    for (int i=1; i<N; i++) {
        scanf(" %d %d", &from, &to);
        tree[from].push_back(to);
        tree[to].push_back(from);
    }

    dfs(start, -1, 1);

    printf("%d\n", res);

    return 0;
}
