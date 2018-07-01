#include <bits/stdc++.h>

using namespace std;

bool simulate(long long k, long long N) {
    long long metade = (N+1)/2;
    long long curr = 0;

    long long tira;
    while (N){
        tira = min(k, N);
        N -= tira;
        curr += tira;
        N -= N/10;
    }
    return curr >= metade;
}

int main() {
    long long N;
    scanf(" %lld", &N);

    long long hi = N;
    long long lo = 1;
    while (hi > lo) {
        long long mid = (hi+lo)/2;
        if (simulate(mid, N)){
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    printf("%lld\n", lo);

    return 0;
}
