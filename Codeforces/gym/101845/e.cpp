#include "bits/stdc++.h"
#define MAX 57

using namespace std;
typedef long long ll;

ll calculate(int n){
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+2; j < n; j++) cnt++;
    }

    return cnt;
}

ll dp[MAX];
int main(){
    int n; scanf("%d", &n);
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 3*calculate(i+1);
    }

    printf("%lld\n", dp[n]);
    return 0;
}
