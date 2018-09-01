#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

#define st first
#define nd second

pair<int, int> pedidos[MAXN];

int main() {
    int T;
    scanf(" %d", &T);

    for (int t=0; t<T; t++) {
        int N;
        scanf(" %d", &N);

        for (int i=0; i<N; i++) {
            scanf(" %d %d", &pedidos[i].st, &pedidos[i].nd);
        }

        sort(pedidos, pedidos+N);

        long long atual = 1;
        int inicio = 1, duracao;
        for (int i=0; i<N; i++) {
            inicio = pedidos[i].st;
            duracao = pedidos[i].nd;
            if (inicio > atual) {
                atual = inicio;
            }
            atual += duracao;
        }
        printf("%lld\n", atual);
    }

    return 0;
}
