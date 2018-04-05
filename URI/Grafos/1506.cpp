#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;

const long long int INF = 999999999;

int dist[MAXN][MAXN];
long long int tempo[MAXN][MAXN];
vector<int> graph;
vector<int> bones;

void init(int n) {
    for (int i=0; i<MAXN; i++) {
        for (int j=0; j<MAXN; j++) {
            tempo[i][j] = dist[i][j] = INF;
        }
        tempo[i][i] = dist[i][i] = 0;
    }
    bones.clear();
    graph.clear();
}

int pior_caminho(int atual, int n, bitset<111> visited){
    if (atual == 0) return 0;

    int worst = 0;
    for (int i=0; i<n; i++){
        if (dist[atual][i] == 1 && visited[i]==false){
            visited[i] = true;
            worst = max(worst, pior_caminho(i, n, visited));
            visited[i] = false;
        }
    }
    return 1+worst;
}

void menor_caminho(int start, int n) {
    priority_queue<pair<int, int>> fila;

    for (int i=0; i<n; i++){
        if (dist[start][i] == 1) {
            fila.push(i);
        }
    }

    while (!fila.empty()) {
        int from = fila.top().second;
        int temp = fila.top().first;
        fila.pop();

        int atual_dist;
        long long int atual_temp;
        for (int to=0; to<n; to++) {
            if (to == from) continue;

            atual_temp = tempo[start][from] + tempo[from][to];
            atual_dist =  dist[start][from] +  dist[from][to];

            if (atual_temp < tempo[start][to]) {
                fila.push(to);
                tempo[start][to] = atual_temp;
                dist[start][to]  = atual_dist;
            } else if (atual_temp == tempo[start][to] && atual_dist > dist[start][to]) {
                fila.push(to);
                tempo[start][to] = atual_temp;
                dist[start][to]  = atual_dist;
            }
        }
    }
}

int main() {
    int T;
    scanf(" %d", &T);

    while (T--) {
        int N, M;
        scanf(" %d %d", &N, &M);

        init(N);

        int from, to;
        long long int weight;
        for (int i=0; i<M; i++) {
            scanf(" %d %d %lld", &from, &to, &weight);
            from--; to--;
            tempo[from][to] = tempo[to][from] = weight;
            dist[from][to] = dist[to][from] = 1;
        }

        /*
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                printf("dist[%d][%d] = %d\n", i, j, dist[i][j]);
            }
        }*/

        int K, P;
        scanf(" %d %d", &K, &P);

        int bone;
        for (int i=0; i<K; i++){
            scanf(" %d", &bone);
            bones.push_back(bone-1);
        }

        int res = 0;

        int count = 0;
        int acum = 0;

        dijkstra(0, N);

        for (int bone : bones) {
            assert(dist[0][bone] < INF);
            bitset<111> vis;
            acum += max(pior_caminho(bone, N, vis), dist[0][bone]);
            //cout << "o pior caminho de " << bone<< " eh: "<< pior_caminho(bone, N, vis)<<endl;
            if ((++count % P) == 0) {
                //cout << res << " ^ " << acum << " = " << (res^acum) << endl;
                res ^= acum;
                acum = 0;
            }
        }

        //cout << res << " ^ " << acum << " = " << (res^acum) << endl;
        res ^= acum;

        printf(res == 0 ? "No\n" : "Yes\n");
        //cout << res <<endl;
    }
    return 0;
}

/*
1
5 6
1 2 1
1 3 1
2 3 1
2 5 2
3 4 1
4 5 1
0 10000
2 2 2 2 2

*/
