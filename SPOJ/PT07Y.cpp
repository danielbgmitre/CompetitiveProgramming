#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int parent[MAXN];
int comp_size[MAXN];

int component(int u){
    if (parent[u]==u) return u;
    return parent[u]=component(parent[u]);
}

void join(int u, int v){
    if (component(u) != component(v)) {
        if (comp_size[component(v)] > comp_size[component(u)]) swap(u, v);
        comp_size[component(u)] += comp_size[component(v)];
        comp_size[component(v)] = 0;
        parent[component(v)] = component(u);
    }
}

void initialize(int n){
    for (int i=0; i<n; i++){
        parent[i] = i;
        comp_size[i] = 1;
    }
}

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);

    bool is_tree = (N-1==M);

    initialize(N);

    int a, b;
    for (int i=0; i<M; i++){
        scanf(" %d %d", &a, &b);
        a--; b--;
        join(a, b);
    }

    if (comp_size[component(0)] != N) is_tree = false;
    if (N == 0) is_tree = true;

    printf("%s\n", is_tree? "YES" : "NO");

    return 0;
}
