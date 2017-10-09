//https://www.urionlinejudge.com.br/judge/pt/problems/view/1224
//Cartões

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 100;

typedef long long int ll;

ll cartoes[MAXN], dp[MAXN][2];

void limpa(int N){
    for (int i=0; i<=N; i++){
        dp[i][0] = dp[i][1] = 0;
    }
}

ll solve(int N, int res){
    int player = 1, previous = 0;

    for (int i=1; i<=N; i++){
        for (int j=0; j<=N-i; j++){
            dp[j][player] = cartoes[j+i]-cartoes[j] -
                            min(dp[j][previous], dp[j+1][previous]);
        }
        swap(player, previous);
    }
    return dp[0][0];
}


int main(){
    int N;
    while (scanf(" %d", &N) != EOF){
        for(int i=1; i<=N; i++){
            scanf(" %lld", &cartoes[i]);
            cartoes[i] += cartoes[i-1];
        }

        limpa(N);

        printf("%lld\n", solve(N, 0));
    }


    return 0;
}
