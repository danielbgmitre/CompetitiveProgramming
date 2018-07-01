#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const lli MOD = 1e9 + 7;
const int MAXN = 3e5 + 10;

lli fat[MAXN];

lli invMod(lli a, lli m){
    lli m0 = m;
    lli y=0, x=1;

    if (m==1) return 0;

    while (a > 1) {
        lli q = a/m;
        lli t = m;

        m = a%m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0){
        x += m0;
    }
    return x;
}

lli fast_pow(lli base, int expo) {
    if (expo <= 0) return 1;
    if (expo&1) return (base*fast_pow(base, expo-1))%MOD;
    lli half = fast_pow(base, expo>>1);
    return (half*half)%MOD;
}

lli comb(int n, int p){
    return fat[n+p-1]
         * invMod((fat[p-1]*fat[n])%MOD, MOD)%MOD;
}

int main() {
    fat[0] = 1LL;
    for (int i=1; i<MAXN; i++){
        fat[i] = (fat[i-1] * i)%MOD;
    }

    int N, C;
    scanf(" %d %d", &N, &C);
    int restantes = C-(N*3);

    lli res = (comb(restantes, N+1)*fat[N])%MOD;
    res = (res*fast_pow(6, N)%MOD+MOD)%MOD;
    printf("%lld\n", res);

    return 0;
}
