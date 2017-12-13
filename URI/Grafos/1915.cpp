#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123;
const int INF  = INT_MAX;

int freq[27], flow[MAXN*2][MAXN*2], parent[MAXN*2];

vector<int> amigos[MAXN], brinq[MAXN];

int value(char c){
    return c-'A'+1;
}

int cripto(char c){
    return value(c) + (26 * freq[value(c)]++);
}

void freq_restart(){
    for (int i=0; i<27; i++) freq[i] = 0;
}

void limpa(){
    for (int i=0; i<MAXN; i++) {
        amigos[i].clear();
        brinq[i].clear();
    }

    for(int i=0; i<2*MAXN; i++){
        for (int j=0; j<2*MAXN; j++){
            flow[i][j] = 0;
        }
    }
}

void parent_restart(){
    for (int i=0; i<2*MAXN; i++) parent[i] = 0;
}

int LCS(vector<int> *a, vector<int> *b){
    vector<vector<int>> matriz(a->size()+1, vector<int>(b->size()+1));

    for (size_t i=0; i<=a->size(); i++){
        matriz[i][0] = 0;
    }

    for (size_t i=0; i<=b->size(); i++){
        matriz[0][i] = 0;
    }

    for (size_t i=1; i<=a->size(); i++){
        for (size_t j=1; j<=b->size(); j++){
            if (a->at(i-1) == b->at(j-1)){
                matriz[i][j] = matriz[i-1][j-1] + 1;
            } else {
                matriz[i][j] = max(matriz[i-1][j], matriz[i][j-1]);
            }
        }
    }

    return matriz[a->size()][b->size()];
}

int retirados(vector<int> *a, vector<int> *b){
    return a->size() + b->size() - 2*LCS(a, b);
}

bool aumentante(int source, int sink){
    parent_restart();
    queue<int> fila;
    fila.push(source);
    parent[source] = source;

    int no;
    while (!fila.empty()){
        no = fila.front(); fila.pop();
        if (no == sink) return true;

        for (int i=1; i<2*MAXN; i++){
            if (flow[no][i] && !parent[i]){
                parent[i] = no;
                fila.push(i);
            }
        }
    }

    return false;
}

int satura(int source, int sink){
    int fluxo = INF;

    int u = sink;
    while (u != source){
        fluxo = min(fluxo, flow[parent[u]][u]);
        u = parent[u];
    }

    u = sink;
    while (u != source){
        flow[parent[u]][u] -= fluxo;
        flow[u][parent[u]] += fluxo;
        u = parent[u];
    }

    return fluxo;
}

int ed_karp(int source, int sink){
    int flow = 0;
    while (aumentante(source, sink)){
        flow += satura(source, sink);
    }
    return flow;
}

int main(){
    int N, M;

    while (scanf(" %d %d", &N, &M) && N+M > 0){
        limpa();
        char nome[123];

        for (int i=0; i<N; i++){
            scanf(" %s", nome);
            freq_restart();
            amigos[i].reserve(101);

            for (size_t j=0; nome[j] != '\0'; j++){
                amigos[i].push_back(cripto(nome[j]));
            }
        }

        for (int i=0; i<M; i++){
            scanf(" %s", nome);
            freq_restart();
            brinq[i].reserve(101);

            for (size_t j=0; nome[j] != '\0'; j++){
                brinq[i].push_back(cripto(nome[j]));
            }
        }

        for (int i=0; i<N; i++){
            flow[0][i*2+1] = 1;
        }

        for (int i=0; i<M; i++){
            flow[i*2+2][245] = 1;
        }

        for (int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if (retirados(&amigos[i], &brinq[j])%5 == 0){
                    flow[i*2+1][j*2+2] = 1;
                }
            }
        }

        int total = ed_karp(0, 245);
        printf("P = %.2f\n", (100.0 * total)/N);
    }

    return 0;
}
