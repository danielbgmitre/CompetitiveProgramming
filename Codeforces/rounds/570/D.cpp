#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 100;

struct query {
    int id;
    int level;
};

int size[MAXN], altura[MAXN], color[MAXN], freq[MAXN][28];
vector<int> graph[MAXN];
vector<query> queries[MAXN];
bitset<MAXN> big, res;

int compute_size(int node, int parent){
    size[node] = 1;
    for (int child : graph[node]) {
        if (child != parent) {
            altura[child] = altura[node]+1;
            size[node] += compute_size(child, node);
        }
    }
    return size[node];
}

bool palindromicable(int h) {
    int impares = 0;
    for (int i=0; i<28; i++) {
        impares += freq[h][i] % 2;
    }
    return (impares <= 1);
}

void add(int node, int parent) {
    freq[altura[node]][color[node]]++;
    for (int child : graph[node]) {
        if (child != parent && !big[child]){
            add(child, node);
        }
    }
}

void remove(int node, int parent) {
    freq[altura[node]][color[node]]--;
    for (int child : graph[node]) {
        if (child != parent && !big[child]) {
            remove(child, node);
        }
    }
}

void sack(int node, int parent, bool keep) {
    int maior = 0, big_child = -1;
    for (int child : graph[node]) {
        if (child != parent && size[child] > maior) {
            maior = size[child];
            big_child = child;
        }
    }
    for (int child : graph[node]) {
        if (child != parent && child != big_child) {
            sack(child, node, false);
        }
    }
    if (big_child != -1) {
        sack(big_child, node, true);
        big[big_child] = 1;
    }

    add(node, parent);

    for (auto &q : queries[node]) {
        res[q.id] = palindromicable(q.level);
    }

    if (big_child != -1) {
        big[big_child] = 0;
    }

    if (!keep) {
        remove(node, parent);
    }
}

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);

    int pai;
    for (int i=2; i<=N; i++){
        scanf(" %d", &pai);
        graph[pai].push_back(i);
        graph[i].push_back(pai);
    }

    char _color;
    for (int i=1; i<=N; i++){
        scanf(" %c", &_color);
        color[i] = _color - 'a';
    }

    int no, h;
    for (int i=0; i<M; i++) {
        scanf(" %d %d", &no, &h);
        queries[no].push_back({i, h-1});
    }

    compute_size(1, -1);
    sack(1, -1, 0);

    for (int i=0; i<M; i++){
        if (res[i]) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
