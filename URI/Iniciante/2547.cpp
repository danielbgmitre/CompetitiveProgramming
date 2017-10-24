//https://www.urionlinejudge.com.br/judge/pt/problems/view/2547
//Montanha Russa

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, A_max, A_min;
    while (scanf(" %d %d %d", &N, &A_min, &A_max) != EOF){
        int vis, res = 0;
        for (int i=0; i<N; i++){
            scanf(" %d", &vis);
            if (vis >= A_min && vis <= A_max){
                res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
