#include <bits/stdc++.h>

using namespace std;

int main() {
    int rapido, lento;
    scanf(" %d %d", &rapido, &lento);

    long long hi = INT_MAX;
    long long lo = 0;

    while (hi > lo) {
        long long mid = (lo+hi)/2;

        if (mid * (lento-rapido) >= lento) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }

    printf("%lld\n", hi);

    return 0;
}
