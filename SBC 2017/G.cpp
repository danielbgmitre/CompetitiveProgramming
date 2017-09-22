//https://www.urionlinejudge.com.br/judge/pt/problems/view/2664
//Ginástica

#include <bits/stdc++.h>

using namespace std;

const int MAXT = 52;
const int MAXN = 1e5 + 10;
const long long int MOD  = 1e9 + 7;


long long int gym[MAXT][MAXN];

int main() {
    int T, M, N;
    scanf(" %d %d %d", &T, &M, &N);

    for (int t=1; t<=T; t++){
        for (int i=M; i<=N; i++){
            if (t == 1) {
                gym[t][i] = 1;
            }

            if (i-1 >= M){
                gym[t+1][i-1] = (gym[t+1][i-1] + gym[t][i])%MOD;
            }
            if (i+1 <= N){
                gym[t+1][i+1] = (gym[t+1][i+1] + gym[t][i])%MOD;
            }
        }
    }

    long long int res = 0;
    for (int i=M; i<=N; i++){
        res = (res + gym[T][i])%MOD;
    }
    cout<<res<<endl;

    return 0;
}
