#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 20;

struct node {
    long long perimeter[50];
    node() {
        memset(perimeter, 0, sizeof(perimeter));
    }
    node merge(const node& other) {
        node res;
        int left=0, right=0;
        for (int i = 0; i < 50; i++) {
            if (left < 50 && perimeter[left] > other.perimeter[right]) {
                res.perimeter[i] = perimeter[left++];
            } else {
                res.perimeter[i] = other.perimeter[right++];
            }
        }
        return res;
    }
};

long long arr[MAXN];
node segtree[4 * MAXN];

node build(int id, int left, int right) {
    if (left == right) {
        segtree[id].perimeter[0] = arr[left];
        return segtree[id];
    }
    int mid = (left + right) / 2;
    node l = build(id * 2, left, mid);
    node r = build(id * 2 + 1, mid+1, right);
    return segtree[id] = l.merge(r);
}

node update(int id, int left, int right, int idx, long long value) {
    if (left == right) {
        if (left == idx) {
            segtree[id].perimeter[0] = value;
        }
    } else if (idx >= left && idx <= right) {
        int mid = (left + right) / 2;
        node l = update(id * 2, left, mid, idx, value);
        node r = update(id * 2 + 1, mid + 1, right, idx, value);
        segtree[id] = l.merge(r);
    }
    return segtree[id];
}

node query(int id, int left, int right, int qL, int qR) {
    if (left > qR || right < qL) {
        return node();
    }
    if (left >= qL && right <= qR) {
        return segtree[id];
    }
    int mid = (left + right) / 2;
    node l = query(id * 2, left, mid, qL, qR);
    node r = query(id * 2 + 1, mid + 1, right, qL, qR);
    return l.merge(r);
}

bool isTriangle(long long a, long long b, long long c) {
    return a < b + c;
}

long long solve(node no) {
    long long* per = no.perimeter;
    for (int i=0; i+2 < 50; i++) {
        if (per[i+2] == 0LL) {
            return 0LL;
        }
        if (isTriangle(per[i], per[i+1], per[i+2])) {
            return per[i] + per[i+1] + per[i+2];
        }
    }
    return 0LL;
}

int main() {
    int N, Q;
    scanf(" %d %d", &N, &Q);

    for (int i=1; i <= N; i++) {
        scanf(" %lld", &arr[i]);
    }

    build(1, 1, MAXN);

    int op, arg1, arg2;
    for (int i=0; i < Q; i++) {
        scanf(" %d %d %d", &op, &arg1, &arg2);
        if (op == 1) {  //update
            update(1, 1, MAXN, arg1, arg2);
        } else {    //query
            node no = query(1, 1, MAXN, arg1, arg2);
            long long ans = solve(no);
            printf("%lld\n", ans);
        }
    }

    return 0;
}
