//https://www.urionlinejudge.com.br/judge/pt/problems/view/1056
//Fatores e Multiplos

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

class Aresta {
public:
    int to, rev, flow, cap;
    Aresta(){}
    Aresta(int _to, int _rev, int _flow, int _cap){
        to = _to; rev = _rev; flow = _flow; cap = _cap;
    }
    int residuo() {return cap-flow;}
};

vector<Aresta*> grafo[MAXN];    //Nao eh permitido alocar tanto na memoria dentro de objeto


class MaxFlow {
public:
    int nodes, *level, *work;

    MaxFlow(int tam){
        nodes = tam;
        level = new int[nodes];
        work = new int[nodes];
    }

    void limpa(){
        for (int i=0; i<nodes; i++) {
            for (size_t j=0; j<grafo[i].size(); j++){
                delete grafo[i][j];
            }
            grafo[i].clear();
        }
    }

    void destroy(){
        limpa();
        delete level;
        delete work;
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

vector<int> A, B;

int main(){
    int T;
    scanf(" %d", &T);

    for (int t=1; t<=T; t++){
        MaxFlow *dinic = new MaxFlow(MAXN);
        int N, M, temp;

        scanf(" %d", &N);
        A.reserve(N);
        for (int i=1; i<=N; i++){
            scanf(" %d", &temp);
            A.push_back(temp);
            dinic->add(i, MAXN-1, 1);
        }

        scanf(" %d", &M);
        B.reserve(M);
        for (int i=1; i<=M; i++){
            scanf(" %d", &temp);
            B.push_back(temp);
            dinic->add(0, 200+i, 1);
        }

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (A[i]+B[j] == 0  || (A[i] != 0 && B[j]%A[i] == 0)){
                    dinic->add(j+201, i+1, 1);
                }
            }
        }

        long long int fluxo = dinic->flow(0, MAXN-1);
        printf("Case %d: %lld\n", t, fluxo);
        dinic->destroy();
        A.clear();
        B.clear();
    }
}
