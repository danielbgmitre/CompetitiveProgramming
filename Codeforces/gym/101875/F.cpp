#include <bits/stdc++.h>

using namespace std;

set<long long> hated;
map<long long, int> loved;

long long total = 1e18;

int main() {
    int N;
    scanf(" %d", &N);

    int lovers = 0;

    int t, s;
    long long l;
    for (int i=0; i<N; i++) {
        scanf(" %d %d", &t, &s);
        if (t == 1) lovers++;
        for (int j=0; j<s; j++) {
            scanf(" %lld", &l);
            if (t == 1) {
                loved[l]++;
            } else {
                hated.insert(l);
            }
        }
    }

    if (lovers == 0) {
        printf("%lld\n", total - hated.size());
    } else {
        for (int v : hated) {
            loved[v] = 0;
        }

        long long res = 0;

        for (auto &p : loved) {
            if (p.second == lovers) res++;
        }
        printf("%lld\n", res++);
    }

    return 0;
}
