//https://www.urionlinejudge.com.br/judge/pt/problems/view/2670
//Máquina de Café

#include <bits/stdc++.h>

using namespace std;

const int INF = 999999999;

int main(){
    int A1, A2, A3;
    scanf(" %d %d %d", &A1, &A2, &A3);

    int res = INF;
    res = min(res, A2*2 + A3*4);
    res = min(res, A1*2 + A3*2);
    res = min(res, A1*4 + A2*2);
    printf("%d\n", res);

    return 0;
}
