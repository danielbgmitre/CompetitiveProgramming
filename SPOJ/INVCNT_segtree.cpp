//http://www.spoj.com/problems/INVCNT/
//INVCNT - Inversion Count (resposta com Segment Tree)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

typedef long long int ll;

pair<ll, ll> arr[MAXN];
int tree[MAXN<<2];

int query(int id, int left, int right, int i, int j){
    if (right < i || left > j){
        return 0;
    }
    if (right <= j && left >= i){
        return tree[id];
    }
    int mid = (left+right)/2;
    return query(id*2, left, mid, i, j) +
           query(id*2+1, mid+1, right, i, j);
}

void insert(int id, int left, int right, int value, int pos){
    if (left <= pos && pos <= right){
        if (left == right) {
            tree[id] = 1;
        } else {
            int mid = (left+right)/2;
            insert(id*2, left, mid, value, pos);
            insert(id*2+1, mid+1, right, value, pos);
            tree[id] = tree[id*2] + tree[id*2+1];
        }
    }
}

int main(){
    int T;
    scanf(" %d", &T);
    while (T--){
        int N;
        scanf(" %d", &N);

        memset(tree, 0, sizeof arr);
        for (int i=0; i<N; i++){
            scanf(" %lld", &arr[i].first);
            arr[i].second = i;
        }
        sort(arr, arr+N);
        ll res = 0;
        for (int i=0; i<N; i++){
            res += query(1, 0, N-1, arr[i].second, N-1);
            insert(1, 0, N-1, arr[i].first, arr[i].second);
        }
        printf("%lld\n", res);
    }
    return 0;
}
