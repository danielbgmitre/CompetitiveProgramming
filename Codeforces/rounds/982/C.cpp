#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

vector<int> graph[MAXN];
int tam[MAXN];
int res = 0;

int dfs(int prev, int actual){
    int curr_tam = 0;
    for (int i=0; i<graph[actual].size(); i++){
        if (graph[actual][i] != prev) {
            curr_tam += dfs(actual, graph[actual][i]);
        }
    }
    tam[actual] = curr_tam+1;
    if (tam[actual]%2 == 0 && prev != actual) res++;
    return tam[actual];
}

int main() {
    int N;
    scanf(" %d", &N);

    int a, b;
    for (int i=0; i<N-1; i++) {
        scanf(" %d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);

    if (tam[1]%2){
        printf("-1\n");
    } else {
        printf("%d\n", res);
    }

    return 0;
}
