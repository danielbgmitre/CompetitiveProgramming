/**
 * https://codeforces.com/problemset/problem/547/B
 * Mike and Feet
 * Sparse table + binary search solution.
 */

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int LOGN[MAXN];

pair<int, int> input[MAXN];   // <A[i], i>
int g[MAXN];
int sparse[20][MAXN];

struct revPairComparator {
    bool operator() (const pair<int, int>& one, const pair<int, int>& another) {
        return one > another;
    }
};

int query(int start, int end) {
    int lg = LOGN[end - start + 1];
    return min(
        sparse[lg][start],
        sparse[lg][end - (1 << lg) + 1]
    );
}

void preCalcLog2(int N) {
    for (int i = 1; i < N; i++) {
        LOGN[i] = log2(i);
    }
}

inline int get(int idx) {
    return input[idx].first;
}

int main() {
    preCalcLog2(MAXN);

    int N;
    scanf(" %d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %d", &input[i].first);
        input[i].second = i;
    }

    for (int i = 0; i < MAXN; i++) {
        sparse[0][i] = get(i);
    }

    for (int sz = 1; (1 << sz) <= N; sz++) {
        for (int i = 0; i + (1 << sz) <= N; i++) {
            sparse[sz][i] = min(
                sparse[sz - 1][i],
                sparse[sz - 1][i + (1 << (sz - 1))]
            );
        }
    }

    sort(input, &input[N], revPairComparator());

    int currentSize = 1;

    for (int i = 0; i < N; i++) {
        int heigth = input[i].first;
        int idx    = input[i].second;
        //printf("{%d, %d}\n", heigth, idx);

        int lo = -1;
        int hi = idx;

        //printf("CALCULANDO X\n");
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;

            //printf("min[%d:%d] = %d\n", mid, idx, query(mid, idx));
            if (query(mid, idx) == heigth) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        int x = hi;

        lo = idx;
        hi = N;

        //printf("CALCULANDO Y\n");
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;

            //printf("min[%d:%d] = %d\n", idx, mid, query(idx, mid));
            if (query(idx, mid) == heigth) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        int y = lo;

        int tam = y - x + 1;

        for (int pos = currentSize; pos <= tam; pos++) {
            g[pos] = heigth;
        }
        currentSize = max(currentSize, tam + 1);
    }

    for (int i = 1; i <= N; i++) {
        printf("%d%c", g[i], " \n"[i == N]);
    }

    return 0;
}
