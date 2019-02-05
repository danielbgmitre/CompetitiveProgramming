/*
 * C - Joyride
 * DP O(N^2) solution
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int START = 1;
const long long INF = LLONG_MAX;

long long price[MAXN], duration[MAXN];
vector<int> adj[MAXN];
bitset<MAXN> vis[MAXN];
long long dp[MAXN][MAXN];

void initialize() {
    for (int i=1; i < MAXN; i++) {
        for (int j=0; j < MAXN; j++) {
            dp[i][j] = INF;
        }
    }
}

void setDP(int i, int j, long long value) {
    if ((i < MAXN) && (j < MAXN)) {
        dp[i][j] = min(dp[i][j], value);
        vis[i][j] = true;
    }
}

void showDP(int rows, int cols) {
    for (int i=0; i <= rows; i++) {
        for (int j=0; j <= cols; j++) {
            printf("%4lld ", dp[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize();

    int X;
    scanf(" %d", &X);
    long long N, M, T;
    scanf(" %lld %lld %lld", &N, &M, &T);

    int a, b;
    for (int i=0; i<M; i++) {
        scanf(" %d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        scanf(" %lld %lld", &duration[i], &price[i]);
    }

    setDP(START, duration[START], price[START]);

    for (int dur = 0; dur <= X; dur++) {
        for (int ride = START; ride <= N; ride++) {
            if (!vis[ride][dur]) continue;
            for (int nxt : adj[ride]) {
                setDP(nxt, dur + duration[nxt] + T, dp[ride][dur] + price[nxt]);
            }
            setDP(ride, dur + duration[ride], dp[ride][dur] + price[ride]);
        }
    }


    long long best = dp[START][X];
    //showDP(N, X + 1);

    if (vis[START][X]) printf("%lld\n", best);
    else printf("It is a trap.\n");

    return 0;
}
