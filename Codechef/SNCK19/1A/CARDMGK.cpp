#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;
long long cards[MAXN];

int main() {
    int T;
    scanf(" %d", &T);

    for (int t=0; t<T; t++) {
        int N;
        scanf(" %d", &N);

        for (int i=0; i<N; i++) {
            scanf(" %lld", &cards[i]);
        }

        int decreases = 0;

        for (int i=1; i<N; i++) {
            decreases += cards[i] < cards[i - 1];
        }

        if (decreases == 0 || (decreases == 1 && cards[0] >= cards[N-1])) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
