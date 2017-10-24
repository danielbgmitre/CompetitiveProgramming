//https://www.urionlinejudge.com.br/judge/pt/problems/view/1135
//Colonia de Formigas

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int LOGN = 18;

struct form {
    vector<int> child;
    int level, parent;
    long long dist, tam;
} colony[MAXN];

int dp[MAXN][LOGN];

void calc_level(int N){
    queue<int> fila;
    fila.push(0);
    colony[0].dist = colony[0].level = 0;

    int no;
    while (!fila.empty()){
        no = fila.front(); fila.pop();

        for (int viz : colony[no].child){
            colony[viz].dist = colony[no].dist + colony[viz].tam;
            colony[viz].level = colony[no].level + 1;
            fila.push(viz);
        }
    }
}

void zera(int N){
    for (int i=0; i<=N; i++){
        colony[i].level = colony[i].dist = colony[i].tam = 0;
        colony[i].child.clear();
        for (int j=0; j<LOGN; j++){
            dp[i][j] = 0;
        }
    }
}

void build(int N){
    for (int j=0; j<LOGN; j++){
		dp[0][j] = 0;
	}

	for (int j=0; j<LOGN; j++){
		for (int i=1; i<=N; i++){
			dp[i][j] = (j == 0)? colony[i].parent : dp[dp[i][j-1]][j-1];
		}
	}
}

int query(int a, int b, int N=MAXN){
	if (colony[b].level < colony[a].level) {swap(a, b);}


	for (int j=LOGN-1; j>=0; j--){
		if (colony[dp[b][j]].level >= colony[a].level){
			b = dp[b][j];
		}
	}

    if (a == b) return a;

	for (int j=LOGN-1; j>=0; j--){
		if (dp[a][j] != dp[b][j]){
			a = dp[a][j];
			b = dp[b][j];
		}
	}

	return dp[a][0];
}

int main(){
    int N;
    while (scanf(" %d", &N) && N){
        zera(N);
        for (int i=1; i<=N-1; i++){
            scanf(" %d %lld", &colony[i].parent, &colony[i].tam);
            colony[colony[i].parent].child.push_back(i);
        }
        build(N);
        calc_level(N);

        int Q, a, b; scanf(" %d", &Q);
        for (int i=0; i<Q; i++){
            scanf(" %d %d", &a, &b);
            printf("%lld", colony[a].dist + colony[b].dist - 2 * colony[query(a, b)].dist);
            if (i < Q-1){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
