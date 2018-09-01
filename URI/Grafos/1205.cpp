#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const size_t INF  = 1e8;

vector<int> graph[MAXN];
size_t peso[MAXN];
size_t dist[MAXN];

void zera(){
    for (int i=0; i<MAXN; i++) {
        peso[i] = 0;
        graph[i].clear();
        dist[i] = INF;
    }
}

void dijkstra(int inicio, int fim) {
    dist[inicio] = peso[inicio];
    queue<int> fila;
    fila.push(inicio);

    while (!fila.empty()) {
        int curr = fila.front();
        fila.pop();

        for (int viz : graph[curr]) {
            size_t new_dist = dist[curr] + peso[viz];
            if (new_dist < dist[viz]) {
                dist[viz] = new_dist;
                fila.push(viz);
            }
        }
    }
}

int main() {
    int N, M, K;
    double P;
    while (~scanf(" %d %d %d %lf", &N, &M, &K, &P)) {
        zera();

        int a, b;
        for (int i=0; i<M; i++) {
            scanf(" %d %d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int A;
        scanf(" %d", &A);
        for (int i=0; i<A; i++) {
            scanf(" %u", &a);
            peso[a]++;
        }

        int inicio, fim;
        scanf(" %d %d", &inicio, &fim);

        dijkstra(inicio, fim);

        int inimigos = dist[fim];

        //cout << "inimigos: "<<inimigos<<endl;
        if (inimigos > K) {
            printf("0.000\n");
        } else {
            printf("%.3lf\n", pow(P, inimigos));
        }
    }

    return 0;
}
