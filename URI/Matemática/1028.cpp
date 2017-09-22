//https://www.urionlinejudge.com.br/judge/pt/problems/view/1028
//Figurinhas

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return (b==0)? a : gcd(b, a%b);
}

int main(){
    int N;
    scanf(" %d", &N);

    for(int i=0; i<N; i++){
        int F1, F2;
        scanf(" %d %d", &F1, &F2);

        printf("%d\n", gcd(F1, F2));
    }

}
