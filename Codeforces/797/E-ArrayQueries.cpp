//http://codeforces.com/problemset/problem/797/E
//Array queries

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXQ = 1e5 + 10;
const int MAX_SQRT = sqrt(MAXN) + 10;

int arr[MAXN], res[MAXN][MAX_SQRT], SQRT = MAX_SQRT;

void precalc(int N){
    int new_step;
    for (int i=N; i>0; i--){
        for (int j=SQRT; j>0; j--){
            new_step = i + arr[i] + j;
            if (new_step > N){
                res[i][j] = 1;
            } else {
                res[i][j] = res[new_step][j] + 1;
            }
        }
    }
}

int solve(int p, int k, int N){
    int iteracoes = 0;
    while (p <= N){
        p = p + arr[p] + k;
        iteracoes++;
    }
    return iteracoes;
}

int main(){
    int N;
    scanf(" %d", &N);
    for (int i=1; i<=N; i++){   // N = 1-indexed
        scanf(" %d", &arr[i]);
    }
    SQRT = sqrt(N);

    precalc(N);

    int Q, p, k;
    scanf(" %d", &Q);
    for (int i=0; i<Q; i++){
        scanf(" %d %d", &p, &k);
        if (k > SQRT){
            printf("%d\n", solve(p, k, N));
        } else {
            printf("%d\n", res[p][k]);
        }
    }

    return 0;
}
