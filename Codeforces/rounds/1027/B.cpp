#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int N, Q;
    scanf(" %lld %lld", &N, &Q);

    long long int qtd_par, qtd_impar;
    if (N%2 == 0) {
        qtd_par = qtd_impar = N/2LL;
    } else {
        qtd_par = N/2LL;
        qtd_impar = qtd_par + 1LL;
    }

    long long int x, y;
    for (int q=0; q<Q; q++) {
        scanf(" %lld %lld", &y, &x);
        long long int soma = 0LL;
        if (y%2 == 1) {
            soma = (y/2LL) * qtd_par + (y/2LL) * qtd_impar;
        } else {
            soma = ((y/2LL)-1LL) * qtd_par + (y/2LL) * qtd_impar;
        }

        if ((y+1)%2 == 0) {
            soma += (x+1LL)/2LL;
        } else {
            soma += x/2LL;
        }

        long long int res;
        if ((x+y)%2 == 1) {
            soma = ((y-1LL)*N + x) - soma;
            res = ((N*N)+1LL)/2LL + soma;
        } else {
            res = soma;
        }

        printf("%lld\n", res);
    }

    return 0;
}
