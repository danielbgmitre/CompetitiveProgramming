#include <bits/stdc++.h>

using namespace std;

#define SOURCE    0
#define PRINT     1
#define SELECT    2
#define GENERATOR 3

typedef long long ll;

const int MAXN = 1e5 + 100;

struct node {
    int type;
    ll k, k1, k2, a, b, M;
    vector<ll> output;
    node() : type(-1) {}
    node(int t) : type(t) {}
} nodes[MAXN];

vector<int> graph[MAXN];

ll gcd(ll a, ll b) {
    return (b == 0)? a : gcd(b, a % b);
}

ll generator(int idx, ll x, ll input) {
    ll a = gcd(nodes[idx].a, nodes[idx].M);
    ll b = nodes[idx].b % a;
    if (x < b)
        return input;
    ll res = (x - b) / a;
    if ((x - b) % a != 0)
        res++;
    res = min(res, nodes[idx].M / a);

    return res + input;
}

ll source(int idx, ll x, ll input) {
    int hi = nodes[idx].output.size();
    int lo = -1;
    int mid;
    while (hi - 1 > lo) {
        mid = (lo + hi) / 2;
        if (nodes[idx].output[mid] <= x) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return hi + input;
}

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);

    char[100] node_type;
    for (int i = 1; i <= N; i++) {
        scanf(" %s", node_type);
        if (!strcmp(node_type, "source")){
            nodes[i].type = SOURCE;
            int K; ll tmp;
            scanf(" %d", &K);
            for (int k=0; k < K; k++) {
                scanf(" %lld", &tmp);
                nodes[i].output.push_back(tmp);
            }
            continue;
        }
        if (!strcmp(node_type, "print")){
            nodes[i].type = PRINT;
            continue;
        }
        if (!strcmp(node_type, "select")){
            nodes[i].type = SELECT;
            scanf(" %lld %lld", &nodes[i].k1, &nodes[i].k2);
            continue;
        }
        if (!strcmp(node_type, "generator")){
            nodes[i].type = GENERATOR;
            scanf(" %lld %lld %lld", &nodes[i].a, &nodes[i].b, &nodes[i].M);
            continue;
        }

    }

    int a, b;
    for (int i = 1; i <= M; i++) {
        scanf(" %d %d", &a, &b);
        graph[a].push_back(b);
    }



    return 0;
}
