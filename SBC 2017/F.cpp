//https://www.urionlinejudge.com.br/judge/pt/problems/view/2663
//Fase

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int jogadores[MAXN];

int main(){
    int N, K, pontuacao;;
    scanf(" %d %d", &N, &K);

    for (int i=0; i<N; i++){
        scanf(" %d", &pontuacao);
        jogadores[pontuacao]++;
    }

    int current = 0;
    for(int i=MAXN-1; i >= 0; i--){
        current += jogadores[i];
        if (current >= K) break;
    }

    cout << current << endl;

    return 0;
}
