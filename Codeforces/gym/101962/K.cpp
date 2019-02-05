#include <bits/stdc++.h>

using namespace std;

#define likely(x)      __builtin_expect(!!(x), 1)
#define unlikely(x)    __builtin_expect(!!(x), 0)

const int MAXN = 5e4 + 100;

long long int house[3 * MAXN], res[MAXN];

int solve(int i, int N, int turn=1) {
    if (likely(i > N)) {
        return 0;
    }

    int curr = solve(i + (3 * turn), N, turn + 1);
    int plus = house[i + (3 * turn) - 1] - house[i - 1];

    return max(curr, curr + plus);
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=1; i <= N; i++) {
        scanf(" %d", &house[i]);
        house[i] += house[i-1];
    }

    for (int i=N+1; i <= 3 * (N + 1); i++) {
        house[i] = house[i-1];
    }

    for (int i = N; i > 0; i--) {
        res[i] = solve(i, N);
    }

    for (int i=1; i <= N; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}
