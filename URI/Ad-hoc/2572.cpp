//https://www.urionlinejudge.com.br/judge/pt/problems/view/2572
//Escalacao

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;
const int MOD  = 1e9 + 7;

typedef long long int ll;

int pokes[MAXN];
vector<int> tree[MAXN<<2];

vector<int> merge(vector<int> &left, vector<int> &right, int K){
    int i=0, j=0;
    int tam = min((int)(left.size() + right.size()), K);
    vector<int> res(tam);
    for (int pos=0; pos < tam; pos++){
        if (i >= left.size()){
            res[pos] = right[j++];
        } else if (j >= right.size()){
            res[pos] = left[i++];
        } else if (left[i] == 0 && right[j] == 0){
            return res;
        } else {
            if (left[i] > right[j]){
                res[pos] = left[i++];
            } else {
                res[pos] = right[j++];
            }
        }
    }
    return res;
}


void build(int id, int left, int right, int K){
    if (left == right){
        tree[id].push_back(pokes[left]);
    } else {
        int mid = (left+right)/2;
        build(id*2, left, mid, K);
        build(id*2+1, mid+1, right, K);
        tree[id] = merge(tree[id*2], tree[id*2+1], K);
    }
}

vector<int> query(int id, int left, int right, int i, int j, int K){
    vector<int> res;
    if (left > j || right < i){
        return res;
    } else if (left >= i && right <= j){
        return tree[id];
    } else {
        int mid = (left+right)/2;
        vector<int> qLeft = query(id*2, left, mid, i, j, K);
        vector<int> qRight = query(id*2+1, mid+1, right, i, j, K);
        return merge(qLeft, qRight, K);
    }
}

int main(){
    int N, K, R;
    scanf(" %d %d %d", &N, &K, &R);

    for (int i=0; i<N; i++){
        scanf(" %d", &pokes[i]);
    }

    build(1, 0, N, K);

    int arg1, arg2;
    for (int i=0; i<R; i++){
        scanf(" %d %d", &arg1, &arg2);
        vector<int> v = query(1, 0, N, --arg1, --arg2, K);
        ll res = v[0]%MOD;
        for (int i=1; i<K && i<v.size(); i++){
            if (v[i] == 0) break;
            res = (res*v[i])%MOD;
        }

        printf("%lld\n", res);
    }

    return 0;
}
