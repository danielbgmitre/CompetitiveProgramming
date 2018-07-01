//http://codeforces.com/problemset/problem/380/C
//Sereja and Brackets

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

struct node{
    int total, open, closed;
    node(){
        total = open = closed = 0;
    }
    node operator + (const node &other) const {
        node res;
        int comp = min(open, other.closed);
        res.total = total + other.total + comp;
        res.open = open + other.open - comp;
        res.closed = closed + other.closed - comp;
        return res;
    }
};

char brackets[MAXN];
node tree[MAXN<<2];

void build(int id, int left, int right){
    if (left == right){
        if (brackets[left] == '(') {
            tree[id].open = 1;
        } else if (brackets[left] == ')'){
            tree[id].closed = 1;
        }
    } else if (left < right) {
        int mid = (left+right)/2;
        build(id*2, left, mid);
        build(id*2+1, mid+1, right);
        tree[id] = tree[id*2] + tree[id*2+1];
    }
}

node query(int id, int left, int right, int i, int j){
    node res;
    if (left > j || right < i){
        return res;
    }
    if (left >= i && right <= j){
        return tree[id];
    }
    int mid = (left+right)/2;
    node l = query(id*2, left, mid, i, j);
    node r = query(id*2+1, mid+1, right, i, j);
    return l+r;
}

int main(){
    scanf(" %s", brackets);
    int N = strlen(brackets)-1;
    build(1, 0, N);

    int M;
    scanf(" %d", &M);

    int a, b;
    for (int i=0; i<M; i++){
        scanf(" %d %d", &a, &b);
        printf("%d\n", query(1, 0, N, --a, --b).total*2);
    }

    return 0;
}
