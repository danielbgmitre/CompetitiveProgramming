//http://codeforces.com/contest/903/problem/A
//Hungry Student Problem

#include <bits/stdc++.h>

using namespace std;

int DP[105];

void build(){
    DP[0] = 1;

    for (int i=0; i<101; i++){
        if (DP[i]) {
            int atual = DP[i];
            DP[i+3] += atual + 1;
            DP[i+7] += atual + 1;
        }
    }
}

int main(){
    build();

    int T; scanf(" %d", &T);
    while (T--){
        int N;
        scanf(" %d", &N);
        if (DP[N]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
