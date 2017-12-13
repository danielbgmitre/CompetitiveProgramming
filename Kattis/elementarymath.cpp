//https://open.kattis.com/problems/elementarymath
//Elementary Math

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (4*2500)+123;

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

map<long long int, int> compress;
vector<pair<long long int, long long int>> numbers;

int comprimir(long long int a){
    if (compress.count(a) == 0){
        return compress[a] = compress.size()+1;
    }
    return compress[a];
}

int main(){
    int N;
    scanf(" %d", &N);
    MaxFlow *din = new MaxFlow(4*N+100);
    int sink = 4*N+99;

    long long int a, b;

    numbers.push_back({0, 0});

    for (int i=1; i<=N; i++){
        scanf(" %lld %lld", &a, &b);
        numbers.push_back({a, b});
        din->add(0, i, 1);
        din->add(i, N+comprimir(a+b), 1);
        din->add(i, N+comprimir(a-b), 1);
        din->add(i, N+comprimir(a*b), 1);
    }

    for (pair<long long int, int> p : compress){
        din->add(N+p.second, sink, 1);
    }

    if (din->flow(0, sink) == N){
        for (int i=1; i<=N; i++){
            a = numbers[i].first;
            b = numbers[i].second;
            for (size_t j=0;  j<grafo[i].size(); j++){
                if (grafo[i][j]->residuo() == 0){
                    if (grafo[i][j]->to == N+comprimir(a+b)){
                        printf("%lld + %lld = %lld\n", a, b, a+b);
                    } else if (grafo[i][j]->to == N+comprimir(a-b)){
                        printf("%lld - %lld = %lld\n", a, b, a-b);
                    } else if (grafo[i][j]->to == N+comprimir(a*b)){
                        printf("%lld * %lld = %lld\n", a, b, a*b);
                    }
                    break;
                }
            }
        }
    } else {
        printf("impossible\n");
    }
    din->destroy();

    return 0;
}
