//http://acm.timus.ru/problem.aspx?space=1&num=1118
//Nontrivial Numbers

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int divisores[MAXN];

int main(){
    int a, b;
    scanf(" %d %d", &a, &b);

    for (int i=1; i<=b; i++){
        for (int j=i+i; j<=b; j+=i){
            divisores[j] += i;
        }
    }

    double best = 99999999;
    int ans = -1;
    for (int i=a; i <= b; i++){
        if (((double)divisores[i]) / i < best){
            best = ((double)divisores[i]) / i;
            ans = i;
        }
    }
    cout << ans <<endl;
    return 0;
}
