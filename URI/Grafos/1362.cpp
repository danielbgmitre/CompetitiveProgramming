//https://www.urionlinejudge.com.br/judge/pt/problems/view/1362
//Minha Camiseta me Serve

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 38;
const int INF  = INT_MAX;

int parent[MAXN], graph[MAXN][MAXN];

void zera(){
    for (int i=0; i<MAXN; i++){
        for (int j=0; j<MAXN; j++){
            graph[i][j] = 0;
        }
        parent[i] = 0;
    }
}

void limpa_parent(int N){
    for (int i=0; i<=N; i++) parent[i] = 0;
}

bool aumentante(int source, int sink){
    queue<int> fila;
    limpa_parent(MAXN);
    fila.push(source);

    while (!fila.empty()){
        int no = fila.front(); fila.pop();

        if (no == sink) return true;

        for (int i=1; i<MAXN; i++){
            if (graph[no][i] && !parent[i]){
                parent[i] = no;
                fila.push(i);
            }
        }
    }
    return false;
}

int satura(int source, int sink){
    int v = sink;
    int corte = INF;
    while (source != sink){
        corte = min(corte, graph[parent[sink]][sink]);
        sink = parent[sink];
    }

    sink = v;
    while (source != sink){
        graph[parent[sink]][sink] -= corte;
        graph[sink][parent[sink]] += corte;
        sink = parent[sink];
    }
    return corte;
}

int ed_karp(int source, int sink){
    int res = 0;
    while (aumentante(source, sink)){
        res += satura(source, sink);
    }
    return res;
}

int main(){
    map<string, int> parser = {{"XXL", 31}, {"XL", 32}, {"L" , 33},
                               {"M"  , 34}, {"S" , 35}, {"XS", 36}};

    int T;
    scanf(" %d", &T);
    while (T--){
        zera();

        int N, M;
        scanf(" %d %d", &N, &M);

        char a[10], b[10];
        for (int i=1; i<=M; i++){
            scanf(" %s %s", a, b);
            graph[0][i] = 1;
            graph[i][parser[a]] = 1;
            graph[i][parser[b]] = 1;
        }

        for (int i=31; i<=36; i++){
            graph[i][37] = N/6;
        }

        if (ed_karp(0, 37) < M){
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

}
