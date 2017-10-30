//http://acm.timus.ru/problem.aspx?space=1&num=1028
//Stars

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 32123;

int BIT[MAXN];
int RES[MAXN];

void add(int x){
    while (x < MAXN){
        BIT[x]++;
        x += x & (-x);
    }
}

int query(int y){
    int res = 0;
    while (y){
        res += BIT[y];
        y -= y & (-y);
    }
    return res;
}

int main(){
    int N, x, y;
    scanf(" %d", &N);

    for (int i=0; i<N; i++){
        scanf(" %d %d", &x, &y);
        x++; y++;

        RES[query(x)]++;
        add(x);
    }

    for (int i=0; i<N; i++){
        printf("%d\n", RES[i]);
    }


    return 0;
}
