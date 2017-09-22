//https://www.urionlinejudge.com.br/judge/pt/problems/view/2660
//Cigarras Periódicas
#include <bits/stdc++.h>

using namespace std;

typedef long long int lld;

lld gdc(lld a, lld b){
    return (b==0)? a : gdc(b, a%b);
}

lld mmc(lld a, lld b){
    return (a*b)/gdc(a, b);
}

int main(){
    lld N, L, c;
    scanf(" %lld %lld", &N, &L);

    lld multiplo = 1;
    for(int i=0; i<N; i++){
        scanf(" %lld", &c);
        multiplo = mmc(multiplo, c);
    }

    lld ans = 1, longest_time = multiplo;
    for (int i=2; i<10000; i++){
        lld temp = mmc(multiplo, i);
        if (temp > longest_time && temp <= L) {
            ans = i;
            longest_time = temp;
        }
    }
    cout << ans <<endl;

    return 0;
}
