#include <bits/stdc++.h>

using namespace std;

#define count_bits(x) __builtin_popcountll(x)

int main() {
    int T;
    scanf(" %d", &T);

    for (int test=0; test<T; test++) {
        long long a;
        scanf(" %lld", &a);
        printf("%d\n", count_bits( a ^ (a-1) ));
    }

    return 0;
}
