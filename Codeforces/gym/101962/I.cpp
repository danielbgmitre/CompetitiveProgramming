#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

long long mansion[MAXN], toLeft[MAXN], toRight[MAXN];
struct node {
    long long toleft, toright;
    node() : toleft(0LL), toright(0LL) {}
    node(l, r) : toleft(l), toright(r) {}
} tree[MAXN];

long long build()

int main() {
    int N, Q;
    scanf(" %d %d", &N, &Q);

    for (int i=1; i<=N; i++) {
        scanf(" %ld", &mansion[i]);
    }

    int op, idx, H;
    for (int q=0; q<Q; q++) {
        scanf(" %d %d %ld", &op, &idx, &H);
        if (op == 1) {
            mansion[idx] = H;
            update(1, 1, N, )
        }
    }


    return 0;
}
