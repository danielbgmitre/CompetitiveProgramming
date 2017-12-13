//https://www.urionlinejudge.com.br/judge/pt/problems/view/1500
//Consultas Horriveis - BIT

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

const int MAXN = 1e5 + 10;

int N = 0;

lli bitA[MAXN], bitB[MAXN];

void add(lli BIT[], int p, lli v){
    while (p <= N){
        BIT[p] += v;
        p += p & (-p);
    }
}

void add(lli BIT[], int p, int q, lli v){
    add(bitA, p, v);
    add(bitA, q+1, -v);
    add(bitB, p, v * (p-1));
    add(bitB, q+1, -v * q);
}

lli get(lli BIT[], int p){
    lli res = 0;
    while (p > 0){
        res += BIT[p];
        p -= p & (-p);
    }
    return res;
}

lli get(int p){
    return get(bitA, p) * p - get(bitB, p);
}

lli get(int p, int q){
    return get(q) - get(p-1);
}

int main(){
    int T;
    scanf(" %d", &T);

    while (T--){
        int C;
        scanf(" %d %d", &N, &C);
        for (int i=0; i<=N; i++){
            bitA[i] = bitB[i] = 0;
        }

        int op, p, q;
        lli v;
        for (int i=0; i<C; i++){
            scanf(" %d", &op);
            if (op == 0){
                scanf(" %d %d %lld", &p, &q, &v);
                add(bitA, p, q, v);
            } else {
                scanf(" %d %d", &p, &q);
                printf("%lld\n", get(p, q));
            }

        }
    }



    return 0;
}
