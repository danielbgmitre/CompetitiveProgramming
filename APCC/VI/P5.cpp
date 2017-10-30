//http://acm.timus.ru/problem.aspx?space=1&num=1930
//Ivan's Car

#### WA
##TO-DO
# Corrigir mudanca de marcha

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;

int changes[MAXN][MAXN];
vector<int> viz[MAXN];

int bfs(int from, int goal, int N){
    bool visited[N] = {false};

    queue<pair<int, int>> fila;
    fila.push({0, from});
    visited[from] = true;

    while (!fila.empty()){
        int dist = fila.front().first;
        int no = fila.front().second;

        if (no == goal) return dist;

        for (int adj : viz[no]){
            if (!visited[adj]){
                fila.push({dist+changes[no][adj], adj});
                visited[adj] = true;
            }
        }
        fila.pop();
    }
    return -1;
}

int main(){
    int N, M;
    scanf(" %d %d", &N, &M);

    int a, b;
    for (int i=0; i<M; i++){
        scanf(" %d %d", &a, &b);
        viz[a].push_back(b);
        viz[b].push_back(a);
        changes[a][b] = 1;
        changes[b][a] = 0;
    }

    scanf(" %d %d", &a, &b);
    if (a == b){
        cout << 0 <<endl;
    } else {
        cout << bfs(a, b, N) << endl;
    }

    return 0;
}
