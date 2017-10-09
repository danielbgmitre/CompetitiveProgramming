//https://www.urionlinejudge.com.br/judge/pt/problems/view/1221
//Primo Rápido

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;

bool crivo[MAXN];
vector<int> primos;

void inicia(){
    for (int i=0; i<MAXN; i++) crivo[i] = true;
    crivo[0] = crivo[1] = false;
}

bool isPrime(long long int number){
    for (int p : primos){
        if (p > sqrt(number)) break;

        if (number%p == 0) return false;
    }
    return true;
}

int main(){
    inicia();
    int N;
    scanf("%d", &N);

    for (int i=0; i<MAXN; i++){
        if (crivo[i]){
            primos.push_back(i);
            for (int j=i*2; j<MAXN; j+=i){
                crivo[j] = false;
            }
        }
    }

    long long int p;
    while (N--){
        scanf("%lld", &p);

        if (isPrime(p)){
            printf("Prime\n");
        } else {
            printf("Not Prime\n");
        }
    }

    return 0;
}
