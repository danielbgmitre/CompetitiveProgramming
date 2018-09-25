#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;

class Aresta {
public:
    int to, rev, flow, cap;
    Aresta() {}
    Aresta(int _to, int _rev, int _flow, int _cap)
    : to(_to), rev(_rev), flow(_flow), cap(_cap) {}
    int residuo() {
        return cap-flow;
    }
};

class MaxFlow {
public:
    size_t nodes;
    int *level, *work;
    vector<Aresta*> *grafo;

    MaxFlow(size_t tam) {
        nodes = tam;
        level = new int[nodes];
        work = new int[nodes];
        grafo = new vector<Aresta*>[tam];
    }

    virtual ~MaxFlow() {
        limpa();
        delete level;
        delete work;
        delete[] grafo;
    }

    void limpa() {
        for (size_t i=0; i<nodes; i++) {
            for (size_t j=0; j<grafo[i].size(); j++) {
                delete grafo[i][j];
            }
            grafo[i].clear();
        }
    }

    void add(int s, int t, int cap) {
        Aresta *a = new Aresta(t, grafo[t].size(), 0, cap);
        Aresta *b = new Aresta(s, grafo[s].size(), 0, 0);
        grafo[s].push_back(a);
        grafo[t].push_back(b);
    }

    bool bfs(int source, int sink) {
        for (size_t i=0; i<nodes; i++) {
            level[i] = -1;
        }
        queue<int> fila;
        level[source] = 0;
        fila.push(source);

        int atual;
        while (!fila.empty()) {
            atual = fila.front(); fila.pop();
            for (Aresta *a : grafo[atual]) {
                if (level[a->to] < 0  && a->flow < a->cap) {
                    level[a->to] = level[atual] + 1;
                    fila.push(a->to);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int source, int sink, int flow) {
        if (source == sink) return flow;

        for (int &i=work[source]; i<grafo[source].size(); i++) {
            Aresta *a = grafo[source][i];
            if (a->cap <= a->flow) continue;
            int to = a->to;
            if (level[to] == level[source] + 1) {
                int delta = dfs(to, sink, min(flow, a->cap - a->flow));
                if (delta > 0) {
                    a->flow += delta;
                    grafo[to][a->rev]->flow -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }

    long long flow(int source, int sink) {
        long long res = 0;
        while (bfs(source, sink)) {
            for (size_t i=0; i<nodes; i++) work[i] = 0;
            int delta = dfs(source, sink, INT_MAX);
            while (delta) {
                res += delta;
                delta = dfs(source, sink, INT_MAX);
            }
        }
        return res;
    }
};

MaxFlow din = MaxFlow(MAXN);

char nums[MAXN][11];

int pali(int idx){
    int leni = strlen(nums[idx]);
    for (int i=0; i<leni/2; i++){
        if (num[idx][i] != num[idx][leni-i]) return 0;
    }
    return 1;
}

int is47(int idx){
    int leni = strlen(nums[idx]);
    for (int i=0; i<leni/2; i++){
        if (num[idx][i] != '4' && num[idx][i] != '7') return 0;
    }
    return 2;
}

int grupo[MAXN];
bitset <MAXN> temAmigos;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    bool gamb = false;
    for (int i=1; i<=n; i++){
        scanf(" %s", nums[i]);
        grupo[i] = is47(i) + pali(i);
        gamb = gamb || (grupo[i] == 0);
    }
    if (gamb){
        printf("No\n");
        return 0;
    }

    for (int i=1; i<=n; i++){
        if (grupo[i] < 3){
            for (int j=i+1; (j-i <= k) && (j<=n); j++){
                if (grupo[j] == grupo[i]){
                    temAmigos[j] = true;
                    temAmigos[i] = true;
                }
            }
        }
    }

    for (int i=1; i<=n; i++){
        if (grupo[i] == 3){
            din.add(0, i, 1);
            for (int j=i+1; (j-i <= k) && (j<=n); j++){
                if (!temAmigos[j] && grupo[j] != 3){
                    din.add(i, j, 1);
                }
            }
        } else if (grupo[i] < 3 && !temAmigos[i]){
            din.add(i, MAXN-1, 1);
        }
    }
    


    return 0;
}
