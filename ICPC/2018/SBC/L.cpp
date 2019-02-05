/*
 * Looking for the Risk Factor
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2914
 * O(n.sqrt(n)) solution
 */

#include <bits/stdc++.h>

using namespace std;

struct query {
    int n, k, idx;
    query() : n(0), k(0), idx(0) {}
    bool operator < (const query& other) const {
        return k < other.k;
    }
};

const int MAXN = 1e5 + 100;

long long bit[MAXN];

void add(int idx) {
    while (idx < MAXN) {
        bit[idx]++;
        idx += idx & (-idx);
    }
}

long long sum(int idx) {
    long long ans = 0;
    while (idx > 0) {
        ans += bit[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

query queries[MAXN]; // pair(k, n);

vector<int> primes;
int maxPrime[MAXN];

void calc_primes() {
    for (int i=2; i < MAXN; i++) {
        if (maxPrime[i] == 0) {
            maxPrime[i] = i;
            primes.push_back(i);
            for (long long j = (long long) (2LL * i); j < (long long) MAXN; j += (long long) i) {
                maxPrime[j] = i;
            }
        }
    }
    primes.push_back(99999999);
}

int next_prime_idx = 0;
inline int next_prime(){
    return primes[next_prime_idx];
}

void crive(int N) {
    for (int i = N; i < MAXN; i += N) {
        if (maxPrime[i] == N) {
            add(i);
        }
    }
    next_prime_idx++;
}

long long res[MAXN];

int main() {
    calc_primes();

    int Q;
    scanf(" %d", &Q);

    for (int i=0; i<Q; i++) {
        scanf(" %d %d", &queries[i].n, &queries[i].k);
        queries[i].idx = i;
    }

    sort(queries, queries + Q);

    for (int i=0; i < Q; i++) {
        while (next_prime() <= queries[i].k) {
            crive(next_prime());
        }
        res[queries[i].idx] = sum(queries[i].n);
    }

    for (int i=0; i < Q; i++) {
        printf("%lld\n", res[i]);
    }

    return 0;
}
