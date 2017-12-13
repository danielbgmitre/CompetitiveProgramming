//http://www.spoj.com/problems/FASTFLOW/
//Fast Maximum Flow

#include <bits/stdc++.h>

using namespace std;

class Aresta {
public:
    int to, rev, flow, cap;
    Aresta(){}
    Aresta(int _to, int _rev, int _flow, int _cap){
        to = _to; rev = _rev; flow = _flow; cap = _cap;
    }
};

const int MAXN = 5555;
vector<Aresta*> grafo[MAXN];

class MaxFlow {
public:
    int nodes, *level, *work;

    MaxFlow(int tam){
        nodes = tam;
        level = new int[nodes];
        work = new int[nodes];
    }

    virtual ~MaxFlow(){
        limpa();
        delete level;
        delete work;
    }
    
    void limpa(){
        for (int i=0; i<nodes; i++) {
            for (size_t j=0; j<grafo[i].size(); j++){
                delete grafo[i][j];
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


int main(){
    int N, M;
    scanf(" %d %d", &N, &M);
    MaxFlow *din = new MaxFlow(N+5);

    int from, to, cap;
    for (int i=0; i<M; i++){
        scanf(" %d %d %d", &from, &to, &cap);
        din->undirectedAdd(from, to, cap);
    }

    printf("%lld\n", din->flow(1, N));
    delete din;

    return 0;
}
