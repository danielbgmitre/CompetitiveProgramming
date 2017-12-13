#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123;

class Aresta {
private:
    void init(){
        from = to = -1;
        reversa = NULL;
        capacity = 0;
    }

public:
    int from, to, capacity;
    Aresta *reversa;
    Aresta(){
        init();
    }

    Aresta(int cap){
        init();
        capacity = cap;
    }

    Aresta(int from, int to, int cap){
        init();
        this->from = from;
        this->to = to;
        capacity = cap;
    }

    void send(int flow){
        if (flow > capacity) throw "Max Capacity Exceeded";
        capacity -= flow;
        reversa->capacity += flow;
    }

    void destroy(){
        delete reversa;
        reversa = NULL;
        delete this;
    }
};

class EdmondsKarp {
private:
    int size;
    Aresta *parent[MAXN];
    vector<Aresta*> *graph;;
    void limpaParent(){
        for (int i=0; i<size; i++){
            parent[i] = NULL;
        }
    }
public:
    EdmondsKarp(int N){
        size = N;
        graph = new vector<Aresta*>[size];
    }

    void add(int from, int to, int cap){
        Aresta *arFrom = new Aresta(from, to, cap);
        Aresta *arTo = new Aresta(to, from, cap);
        arFrom->reversa = arTo;
        arTo->reversa = arFrom;
        graph[from].push_back(arFrom);
        graph[to].push_back(arTo);
    }

    bool findPath(int source, int sink){
        queue<int> fila;
        fila.push(source);
        limpaParent();
        parent[source] = new Aresta();

        int atual;
        while (!fila.empty()){
            atual = fila.front(); fila.pop();
            if (atual == sink) return true;

            for (Aresta *a : graph[atual]){
                if (a->capacity && parent[a->to] == NULL){
                    parent[a->to] = a;
                    fila.push(a->to);
                }
            }
        }

        delete parent[source];
        return false;
    }

    int satura(int source, int sink, int corte){
        if (source == sink) {
            return corte;
        }

        int curr_flow = satura(source,
                               parent[sink]->from,
                               min(corte, parent[sink]->capacity));

        parent[sink]->send(curr_flow);

        return curr_flow;
    }

    int satura(int source, int sink){
        return satura(source, sink, INT_MAX);
    }

    void clear(){
        for (int i=0; i<size; i++){
            for (size_t j=0; j<graph[i].size(); j++){
                graph[i][j]->destroy();
            }
            graph[i].clear();
        }
    }

    int sendAll(int source, int sink){
        int res = 0;
        while (findPath(source, sink)){
            res += satura(source, sink);
        }
        return res;
    }
};

int chtoint(char ch){
    return ch-'A';
}



int main(){
    int N;
    scanf(" %d", &N);

    EdmondsKarp *ed = new EdmondsKarp(MAXN);

    char from, to;
    int cap;
    for (int i=0; i<N; i++){
        scanf(" %c %c %d", &from, &to, &cap);
        ed->add(chtoint(from), chtoint(to), cap);
    }

    printf("%d\n", ed->sendAll(chtoint('A'), chtoint('Z')));
    delete ed;

    return 0;
}
