//https://www.urionlinejudge.com.br/judge/pt/problems/view/2658
//Acordes Intergalaticos

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

int tree[MAXN<<2][9];
int lazy[MAXN<<2];
int res[9];
int temp[9];

void build(int id, int left, int right) {
    tree[id][1] = right - left + 1;
    if (left < right) {
        int mid = (left + right) / 2;
        build(id*2, left, mid);
        build(id*2+1, mid+1, right);
    }
}

void push_lazy(int id, int left, int right) {
    if (lazy[id]) {
        memset(temp, 0, sizeof temp);

        for (int i=0; i<9; i++) {
            temp[(i + lazy[id]) % 9] = tree[id][i];
        }

        for (int i=0; i<9; i++) {
            tree[id][i] = temp[i];
        }

        if (left < right) {
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }

        lazy[id] = 0;
    }
}

void query(int id, int left, int right, int a, int b) {
    push_lazy(id, left, right);
    if (a > right || b < left) return;
    if (left >= a && right <= b) {
        for (int i=0; i<9; i++) {
            res[i] += tree[id][i];
        }
    } else {
        int mid = (left + right) / 2;
        query(id*2, left, mid, a, b);
        query(id*2+1, mid+1, right, a, b);
    }
}

void update(int id, int left, int right, int a, int b, int value) {
    if (a > right || b < left) return;
    if (left >= a && right <= b) {
        lazy[id] += value;
    } else {
        int mid = (left + right) / 2;
        update(id*2, left, mid, a, b, value);
        update(id*2+1, mid+1, right, a, b, value);

        for (int i=0; i<9; i++) {
            tree[id][i] = tree[id*2][i] + tree[id*2+1][i];
        }
    }
    push_lazy(id, left, right);
}

int main(){
    int N, Q;
    scanf(" %d %d", &N, &Q);
    build(1, 0, N-1);

    for (int i=0; i<Q; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);

        memset(res, 0, sizeof res);
        query(1, 0, N-1, a, b);

        int most = 0, freq = res[0];
        for (int i=1; i<9; i++) {
            if (res[i] >= freq) {
                most = i, freq = res[i];
            }
        }

        //cout << "a tecla mais frequente eh: " << most << endl;
        //cout << "ela aparece "<<freq<<" vezes"<<endl;

        update(1, 0, N-1, a, b, most);
    }

    for (int i=0; i<N; i++) {
        memset(res, 0, sizeof res);
        query(1, 0, N-1, i, i);

        for (int acorde=0; acorde<9; acorde++) {
            if (res[acorde] > 0) {
                printf("%d\n", acorde);
            }
        }
    }

    return 0;
}
