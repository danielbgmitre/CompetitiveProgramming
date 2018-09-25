#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5;
const ll MOD = 1000000007;

ll m[MAXN][MAXN] = {{0, 1, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 1, 0},
                    {0, 0, 0, 0, 1},
                    {0, 1, 4, 9, 16}};

ll res[MAXN] = {0, 0, 0, 0, 1};

void mult(ll m[MAXN][MAXN], ll p[MAXN][MAXN]){

    ll seca[MAXN][MAXN] = {{0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}};

    for (int i=0; i<MAXN; i++){
        for (int j=0; j<MAXN; j++){
            for (int k=0; k<MAXN; k++){
                seca[i][j] += (m[i][k] * p[k][j]) % MOD;
                seca[i][j] %= MOD;
            }
        }
    }


    for (int i=0; i<MAXN; i++){
        for (int j=0; j<MAXN; j++){
            m[i][j] = seca[i][j];
        }
    }
}

void exp(ll m[MAXN][MAXN], ll num){
    if (num == 0 || num == 1) return;


    ll p[MAXN][MAXN] = {{0, 1, 0, 0, 0},
                        {0, 0, 1, 0, 0},
                        {0, 0, 0, 1, 0},
                        {0, 0, 0, 0, 1},
                        {0, 1, 4, 9, 16}};

    exp(m, num/2ll);

    mult(m, m);
    if (num & 1) mult(m, p);
}

int main(){
    ll n;
    scanf("%lld", &n);

    if (n/10ll == 0){
        printf("1\n");
        return 0;
    }

    exp(m, (n/10ll));

    ll ans[MAXN] = {0, 0, 0, 0, 0};
    int comeco = (n % 10ll) >= 5 ? 1 : 0;
    ll desgraca = 0ll;
    for (int i=comeco; i<MAXN; i++){
        for (int j=0; j<MAXN; j++){
            ans[i] += (m[i][j] * res[j]) % MOD;
            ans[i] %= MOD;
        }
        desgraca += ans[i];
        desgraca %= MOD;
    }

    printf("%lld\n", desgraca);

    return 0;
}
