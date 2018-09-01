#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4010;

int arr[MAXN];

int main() {
    int T;
    scanf(" %d", &T);

    for (int test=0; test<T; test++) {
        int N;
        scanf(" %d", &N);

        int _2N = 2*N;

        for (int i=1; i<=_2N; i++) {
            scanf(" %d", &arr[i]);
        }

        int best = 0;

        for (int i=1; i<=N; i++) {
            best = max(best, arr[i] + arr[_2N - i + 1]);
        }

        printf("%d\n", best);

    }
    return 0;
}
