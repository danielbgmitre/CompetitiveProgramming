#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

int color[MAXN], size[MAXN], freq[MAXN];
bitset<MAXN> big;
vector<int> graph[MAXN];
long long ans[MAXN], soma=0, maior_freq=0;

int compute_size(int node, int parent) {
    size[node] = 1;
    for (int child : graph[node]) {
        if (child != parent) {
            size[node] += compute_size(child, node);
        }
    }
    return size[node];
}

void update(int cor) {
    if (freq[cor] > maior_freq) {
        maior_freq = freq[cor];
        soma = cor;
    } else if (freq[cor] == maior_freq) {
        soma += cor;
    }
}

void add(int node, int parent) {
    freq[color[node]]++;
    update(color[node]);

    for (int child : graph[node]) {
        if (child != parent && !big[child]) {
            add(child, node);
        }
    }
}

void remove(int node, int parent) {
    freq[color[node]]--;

    for (int child : graph[node]) {
        if (child != parent && !big[child]) {
            remove(child, node);
        }
    }
}

void sack(int node, int parent, bool keep) {
    int maximo=0, big_child=-1;
    for (int child : graph[node]) {
        if (child != parent && size[child] > maximo) {
            maximo = size[child];
            big_child = child;
        }
    }
    for (int child : graph[node]) {
        if (child != parent && child != big_child) {
            sack(child, node, false);
        }
    }
    if (big_child != -1){
        sack(big_child, node, true);
        big[big_child] = true;
    }
    
    add(node, parent);
    ans[node] = soma;

    if (big_child != -1)
        big[big_child] = false;

    if (!keep) {
        maior_freq = 0;
        soma = 0;
        remove(node, parent);
    }
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        scanf(" %d", &color[i]);
    }

    int a, b;
    for (int i=0; i<N-1; i++) {
        scanf(" %d %d", &a, &b);
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    compute_size(0, -1);
    sack(0, -1, 0);

    for (int i=0; i<N; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");

    return 0;
}
