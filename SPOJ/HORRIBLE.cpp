//http://www.spoj.com/problems/HORRIBLE/
//HORRIBLE - solucao com SQRT Decomposition

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXV = 1e7 + 100;
const int MAX_SQRT = sqrt(MAXN) + 10;

int SQRT = MAX_SQRT;

long long arr[MAXN], blocks[MAX_SQRT][2]; //[0] = intervalo  [1] = posicao

void zera(int N){
    for (int i=0; i<=N; i++){
        arr[i] = 0;
        if (i <= (N/SQRT)){
            blocks[i][0] = blocks[i][1] = 0;
        }
    }
}

void add(int left, int right, int value){
    while (left <= right){
        if (left%SQRT == 0 && left+SQRT-1 <= right){
            blocks[left/SQRT][0] += value;
            left += SQRT;
        } else {
            blocks[left/SQRT][1] += value;
            arr[left] += value;
            left++;
        }
    }
}

long long query(int left, int right){
    long long res = 0;
    while (left <= right){
        if (left%SQRT == 0 && left+SQRT-1 <= right){
            res += SQRT * blocks[left/SQRT][0];
            res += blocks[left/SQRT][1];
            left += SQRT;
        } else {
            res += arr[left] + blocks[left/SQRT][0];
            left++;
        }
    }
    return res;
}

int main(){
    int T;
    scanf(" %d", &T);
    while (T--){
        int N, C;
        scanf(" %d %d", &N, &C);
        SQRT = sqrt(N);
        zera(N);

        int op, p, q, v;
        for (int i=0; i<C; i++){
            scanf(" %d", &op);
            switch (op) {
                case 0:
                    scanf(" %d %d %d", &p, &q, &v);
                    add(p, q, v);
                    break;
                case 1:
                    scanf(" %d %d", &p, &q);
                    printf("%lld\n", query(p, q));
                    break;
            }
        }

    }


    return 0;
}
