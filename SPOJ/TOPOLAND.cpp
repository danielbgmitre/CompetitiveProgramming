//http://www.spoj.com/problems/TOPOLAND/
//To Poland - Solucao com Segment Tree

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

int arr[MAXN], tree[MAXN<<2];

void build(int id, int left, int right){
    tree[id] = -1;
    if (left == right){
        tree[id] = arr[left];
    } else {
        int mid = (left+right)/2;
        build(id*2, left, mid);
        build(id*2+1, mid+1, right);
        tree[id] = max(tree[id*2], tree[id*2+1]);
    }
}

void update(int id, int left, int right, int pos, int value){
    if (left <= pos && pos <= right){
        if (left == right) {
            tree[id] = value;
        } else {
            int mid = (left+right)/2;
            update(id*2, left, mid, pos, value);
            update(id*2+1, mid+1, right, pos, value);
            tree[id] = max(tree[id*2], tree[id*2+1]);
        }
    }
}

int query(int id, int left, int right, int i, int j){
    if (left > j || right < i){
        return -1;
    }
    if (left >= i && right <= j){
        return tree[id];
    }

    int mid = (left+right)/2;
    int a = query(id*2, left, mid, i, j);
    int b = query(id*2+1, mid+1, right, i, j);
    return max(a, b);
}

int main(){
    int T;
    scanf(" %d", &T);

    for (int t=0; t<T; t++){
        int N, M;
        scanf(" %d %d", &N, &M);

        for (int i=0; i<N; i++){
            scanf(" %d", &arr[i]);
        }

        build(1, 0, N);

        char op;
        int Q, arg1, arg2;

        scanf(" %d", &Q);

        printf("Testcase %d:\n", t);
        for (int i=0; i<Q; i++){
            scanf(" %c", &op);

            if (op == 'A'){
                scanf(" %d", &arg1);
                M += arg1;
            } else if (op == 'B'){
                scanf(" %d %d", &arg1, &arg2);
                update(1, 0, N, arg1, arg2);
            } else if (op == 'C'){
                scanf(" %d %d", &arg1, &arg2);
                printf("%d\n", abs(M - query(1, 0, N, arg1, arg2)));
            }
        }
        if (t < T-1) printf("\n");
    }

    return 0;
}
