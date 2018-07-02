#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;
const int MOD  = 1e4;

#define showVector(vec,N) for(int i=0;i<N;i++) for(int j=0; j<N;j++) cout << vec[i][j] << (j+1==N?"\n" : "   ")

typedef vector<vector<int>> vvi;

vvi adj;

void restart(size_t size) {
    adj.resize(size);
    for (vector<int>& v : adj){
        v.resize(size);
        fill(v.begin(), v.end(), 0);
    }
}

vvi mult(const vvi &a, const vvi &b, int modulo, int N) {
    vvi res;
    res.resize(N);
    for (vector<int> &v : res) v.resize(N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            res[i][j] = 0;
            for (int k=0; k<N; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % modulo) % modulo;
            }
        }
    }

    return res;
}

vvi fast_expo(const vvi &matriz, int potencia, int modulo, int N) {
    if (potencia == 1) return matriz;
    if (potencia & 1) {
        return mult(matriz,
            fast_expo(matriz, potencia-1, modulo, N),
            modulo,
            N
        );
    }
    vvi raiz = fast_expo(matriz, potencia>>1, modulo, N);
    return mult(raiz, raiz, modulo, N);
}


int main() {
    int N, L;
    while (scanf(" %d %d", &N, &L) != EOF) {
        restart(N);

        int S, T;
        scanf(" %d %d", &S, &T);
        S--, T--;

        int A, B, C, D;
        for (int i=0; i<N; i++) {
            scanf(" %d %d %d %d", &A, &B, &C, &D);
            A--, B--, C--, D--;
            adj[i][A]++; adj[i][B]++; adj[i][C]++; adj[i][D]++;
        }

        if (L == 0) printf("%d\n", S==T);
        else {
            vvi res = fast_expo(adj, L, MOD, N);
            printf("%d\n", res[S][T]);
        }
    }

    return 0;
}
