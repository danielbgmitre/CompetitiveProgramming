#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

bitset<32000> isPrime;
vector<int> primes;

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

    if (x < 0) x += m0;

    return x;
}


void crivo(int N){
    isPrime.set();

    isPrime[0] = isPrime[1] = 0;
    int raiz = sqrt(N)+2;
    for (int i=0; i<=raiz; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=i*2; j<raiz; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

lli fast_pow(lli a, lli b, lli mod) {
    if (b == 0) return 1;
    if (b&1) return (a * fast_pow(a, b-1, mod)) % mod;
    lli raiz = fast_pow(a, b>>1, mod);
    return (raiz * raiz) % mod;
}

int main() {
    int N, E, C;
    scanf(" %d %d %d", &N, &E, &C);
    crivo(N);
    lli P, Q;
    for (size_t i=0; i<primes.size(); i++) {
        if (N%primes[i] == 0) {
            P = primes[i];
            Q = N/P;
        };
    }

    lli totient = (P-1) * (Q-1);
    lli D = invMod(E, totient);

    //printf("gcd(%d, %d) = %d", totient, E, gcd(totient, E));

    printf("%lld\n", fast_pow(C, D, N));

    return 0;
}
