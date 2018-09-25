#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5000;

class Aresta {
public:
    int to, rev, flow, cap;
    Aresta() {}
    Aresta(int _to, int _rev, int _flow, int _cap) {
        to = _to, rev = _rev, flow = _flow, cap = _cap;
    }
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
        for(size_t i=0; i<nodes; i++) {
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
                if (level[a->to] < 0 && a->flow < a->cap) {
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

    long long int flow(int source, int sink) {
        long long int res = 0;
        while (bfs(source, sink)) {
            for (size_t i=0; i<nodes; i++) work[i] = 0;
            int delta = dfs(source, sink, 9999999);
            while (delta) {
                res += delta;
                delta = dfs(source, sink, 9999999);
            }
        }
        return res;
    }
};

MaxFlow dinic = MaxFlow(MAXN);


int main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int HALF = 30;

    int N;
    string temp;

    cin >> N;
    for (int i=0; i<N; i++) {
        int freq[30];
        memset(freq, 0, sizeof freq);
        int maior = 0;

        for (int team=0; team<3; team++) {
            cin >> temp;
            for (int carrer=0; carrer < temp.size(); carrer++) {
                freq[temp[carrer] - 'A']++;
                maior = max(maior, freq[temp[carrer] - 'A']);
            }
        }
        for (int letra=0; letra<30; letra++) {
            if (freq[letra] == maior) {
                dinic.add(HALF+i+5, letra+1, 1);
            }
        }
    }
    int K;
    cin >> K;

    for (int i=0; i<N; i++) {
        dinic.add(0, HALF+i+5, 1);
    }

    for (int i=0; i<30; i++) {
        dinic.add(i+1, MAXN-1, K);
    }

    cout << dinic.flow(0, MAXN-1) << endl;

    return 0;
}
