/*
 * F - Plug it in
 * Max-flow solution
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;

class Aresta {
public:
    int to, rev, flow, cap, saved_flow;
    Aresta(){}
    Aresta(int _to, int _rev, int _flow, int _cap){
        to = _to; rev = _rev; flow = _flow; cap = _cap; saved_flow = _cap;
    }
    void saveState() {
        saved_flow = flow;
    }
    void restoreState() {
        flow = saved_flow;
    }
};

vector<Aresta*> grafo[MAXN];

class MaxFlow {
public:
    int nodes, *level, *work;

    MaxFlow(int tam){
        nodes = tam;
        level = new int[nodes]();
        work = new int[nodes]();
    }

    virtual ~MaxFlow(){
    }

    void limpa(){
        for (int i=0; i<nodes; i++) {
            for (size_t j=0; j<grafo[i].size(); j++){
                delete grafo[i][j];
                grafo[i][j] = NULL;
            }
            grafo[i].clear();
        }
    }

    void add(int s, int t, int cap){
        Aresta *a = new Aresta(t, grafo[t].size(), 0, cap);
        Aresta *b = new Aresta(s, grafo[s].size(), 0, 0);
        grafo[s].push_back(a);
        grafo[t].push_back(b);
    }

    void undirectedAdd(int s, int t, int cap){
        Aresta *a = new Aresta(t, grafo[t].size(), 0, cap);
        Aresta *b = new Aresta(s, grafo[s].size(), 0, cap);
        grafo[s].push_back(a);
        grafo[t].push_back(b);
    }

    void removeLast(int s) {
        Aresta* node = grafo[s].back(); grafo[s].pop_back();
        grafo[node->to].erase(grafo[node->to].begin() + node->rev);
    }

    bool bfs(int source, int sink){
        for (int i=0; i<nodes; i++){
            level[i] = -1;
        }
        queue<int> fila;
        level[source] = 0;
        fila.push(source);

        int atual;
        while (!fila.empty()){
            atual = fila.front(); fila.pop();
            for (Aresta *a : grafo[atual]){
                if (level[a->to] < 0 && a->flow < a->cap){
                    level[a->to] = level[atual] + 1;
                    fila.push(a->to);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int source, int sink, int flow){
        if (source == sink) return flow;

        for (int &i=work[source]; i<grafo[source].size(); i++){
            Aresta *a = grafo[source][i];
            if (a->cap <= a->flow) continue;
            int to = a->to;
            if (level[to] == level[source]+1){
                int delta = dfs(to, sink, min(flow, a->cap - a->flow));
                if (delta > 0){
                    a->flow += delta;
                    grafo[to][a->rev]->flow -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }

    long long int flow(int source, int sink){
        long long int res = 0;
        while (bfs(source, sink)){
            for (int i=0; i<nodes; i++) work[i] = 0;
            int delta = dfs(source, sink, INT_MAX);
            while (delta){
                res += delta;
                delta = dfs(source, sink, INT_MAX);
            }
        }
        return res;
    }
};

MaxFlow dinic(MAXN);

void dump_state() {
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j < grafo[i].size(); j++) {
            grafo[i][j]->saveState();
        }
    }
}

void restore_state() {
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j < grafo[i].size(); j++) {
            grafo[i][j]->restoreState();
        }
    }
}

const int SOURCE = 0;
const int offset = MAXN / 2;
const int SINK = MAXN - 1;

pair<int, int> graph[80000];

int main() {
    int M, N, K;
    scanf(" %d %d %d", &M, &N, &K);

    for (int i=0; i<K; i++) {
        scanf(" %d %d", &graph[i].first, &graph[i].second);
    }

    for (int i=1; i <= M; i++) {
        dinic.add(SOURCE, i, 1);
    }

    for (int i=1; i <= N; i++) {
        dinic.add(offset + i, SINK, 1);
    }

    for (int i=0; i<K; i++) {
        dinic.add(graph[i].first, offset + graph[i].second, 1);
    }
    long long int res = dinic.flow(SOURCE, SINK);

    dump_state();
    long long extra_flow = 0;
    for (int m=1; m<=M; m++) {
        dinic.add(SOURCE, m, 2);
        extra_flow = max(extra_flow, dinic.flow(SOURCE, SINK));
        restore_state();
    }

    printf("%lld\n", res + extra_flow);

    return 0;
}
