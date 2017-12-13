// ICPC - Argentina Regionals
//https://www.urionlinejudge.com.br/judge/problems/view/1335

#include <bits/stdc++.h>

using namespace std;

const int MAXN = (65e4) + 10;

char entrada[MAXN];

struct SuffixArray {
    long long chave[MAXN];
    int sorted[MAXN], rank[MAXN], *lcp = (int*) chave;

    bool operator() (int i, int j) {
        return chave[i] < chave[j];
    }

    void build(int N){
        for (int i=0; i<N; i++){
            sorted[i] = i;
            chave[i] = entrada[i];
        }

        sort(sorted, sorted+N, SuffixArray());

        for (int k=1;; k<<1){
            for (int i=0; i<N; i++){
                if (i > 0 && chave[sorted[i-1]] == chave[sorted[i]]){
                    rank[sorted[i]] = chave[sorted[i-1]];
                } else {
                    rank[sorted[i]] = i;
                }
            }
            if (k < N){
                for (int i=0; i<N; i++){
                    chave[i] = rank[i] * (N+1LL);
                    if (i+k < N){
                        chave[i] += rank[i+k]+1;
                    }
                }
            } else {
                break;
            }
            sort(sorted, sorted+N, SuffixArray());
        }

        for (int i=0, sz=0; i<N; i++) {
            if (rank[i] > 0){
                int j = sorted[rank[i] - 1];
                while (entrada[i+sz] == entrada[j+sz]){
                    sz++;
                }
                lcp[rank[i]] = sz;
                if (sz > 0){
                    sz--;
                }
            }
        }
        lcp[0] = 0;
    }
} suffix;

int main(){
    int F;
    while (scanf(" %d", &F) && F != 0){
        int N = 0;
        entrada[0] = '\0';
        char buffer[10101];
        for (int i=0; i<F; i++){
            scanf(" %s", buffer);

            int tam = strlen(buffer);
            strcat(entrada+N, buffer);
            N += tam;
            entrada[N++] = 'a' - i - 1;
            entrada[N] = '\0';
        }

        suffix.build(N);

        vector<int> L(N), who(N);
        for (int i=N-1, k, len; i >= 0; i--){
            if (entrada[i] < 'a') {
                len = 0;
                k = 'a' - entrada[i] - 1;
            } else {
                len++;
                L[suffix.rank[i]] = len;
                who[suffix.rank[i]] = k;
            }
        }

        set<long long> res;
        for (int i=0; i<N; i++){
            if (L[i] == 0) continue;

            for (int len = suffix.lcp[i] + 1; len <= L[i]; len++){
                long long mask = 1LL << who[i];
                for (int j=i-1; suffix.lcp[j] >= len; j--){
                    mask |= (1LL << who[j]);
                }
                res.insert(mask);
            }
        }

        printf("%d\n", res.size());
    }

    return 0;
}
