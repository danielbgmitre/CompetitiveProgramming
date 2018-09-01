#include <bits/stdc++.h>

using namespace std;

inline long long ABS(long long x) {
    return x >= 0LL ? x : -x;
}

int main() {
    long long N, st_X, st_Y, end_X, end_Y;
    scanf(" %lld %lld %lld %lld %lld", &N, &st_X, &st_Y, &end_X, &end_Y);

    long long distance = ABS(st_X - end_X) + ABS(st_Y - end_Y);

    if (distance == 0LL)
        distance = 2LL;

    long long res = N - distance + 1LL;
    res = (res+1LL)/2LL;

    if (distance > N) res = 0LL;

    printf("%lld\n", res);

    return 0;
}
