#include <bits/stdc++.h>
#define MAX 10007
using namespace std;


vector<int> valores;
long long dp[MAX];
int main(){
    int n; scanf("%d", &n);

    for(int i= 0; i < n; i++){
        int val; scanf("%d", &val);

        valores.push_back(val);
    }

    sort(valores.rbegin(), valores.rend());

    long long ans = 0;
    dp[0] = 1;
    for(int i = 0; i < valores.size(); i++){
        //cout << valores[i] << endl;
        dp[i+1] = valores[i]*dp[i];
    }

    for(int i = 0; i <= n; i++) ans += dp[i];

    printf("%lld\n", ans);

    return 0;
}
