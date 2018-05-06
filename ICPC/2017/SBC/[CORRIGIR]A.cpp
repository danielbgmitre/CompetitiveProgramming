//https://www.urionlinejudge.com.br/judge/pt/problems/view/2658
//Acordes Intergalaticos

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int tree[MAXN][9], lazy[MAXN], temp[9], res[9];

void lazy_upd(int id, int left, int right){
    if (lazy[id]){
        memset(temp, 0, sizeof temp);
        cout << "acumulado: "<<lazy[id]<<endl;
        cout << "antes:  ";
        for (int i=0; i<9; i++){
            cout << " "<< tree[id][i];
            temp[(i+lazy[id]) % 9] = tree[id][i];
        }
        cout << endl<< "depois: ";
        for (int i=0; i<9; i++){
            tree[id][i] = temp[i];
            cout << " " << tree[id][i];
        }
        if (left < right){
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        cout << endl;
        lazy[id] = 0;
    }
}

void update(int id, int left, int right, int a, int b, int value){
    lazy_upd(id, left, right);
    if (a > right || b < left) return;
    if (left >= a && right <= b) {
        lazy[id] += value;
        lazy_upd(id, left, right);
    } else {
        int mid = (left+right)/2;
        update(id*2, left, mid, a, b, value);
        update(id*2+1, mid+1, right, a, b, value);
    }
}

void query(int id, int left, int right, int a, int b){
    lazy_upd(id, left, right);
    if (a > right || b < left) {
        return;
    }
    if (left >= a && right <= b){
        for (int i=0; i<9; i++){
            res[i] += tree[id][i];
        }
    } else {
        int mid = (left+right)/2;
        query(id*2, left, mid, a, b);
        query(id*2+1, mid+1, right, a, b);
    }
}

void build(int id, int left, int right){
    if (left == right){
        tree[id][1] = 1;
    } else {
        int mid = (left+right)/2;
        build(id*2, left, mid);
        build(id*2+1, mid+1, right);
        tree[id][1] = tree[id*2][1] + tree[id*2+1][1];
    }
}

int main(){
    int N, Q;
    scanf(" %d %d", &N, &Q);
    build(1, 0, N-1);

    int a, b;
    for (int i=0; i<Q; i++){
        scanf(" %d %d", &a, &b);

        memset(res, 0, sizeof res);
        query(1, 0, N-1, a, b);

        int idx = 0, maior = res[0];
        for (int j=1; j<9; j++){
            if (res[j] >= maior){
                maior = res[j];
                idx = j;
            }
        }
        cout << "mais frequente: "<<idx<<endl;

        update(1, 0, N-1, a, b, idx);
    }

    for (int i=0; i<N; i++){
        memset(res, 0, sizeof res);
        query(1, 0, N-1, i, i);
        for (int j=0; j<9; j++){
            if (res[j]){
                printf("res %d: %d\n", i, j);
                break;
            }
        }
    }


    return 0;
}
