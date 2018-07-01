//http://codeforces.com/problemset/problem/86/D
//Powerful Array - solucao com Mo's Algorithm

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 10;
const int MAXQ = 2e5 + 10;
const int BIG  = 1e6 + 10;
//numero magico: 1.514

int SQRT_SIZE = sqrt(MAXN);

typedef long long int ll;

struct query{
    int left, right, id;

    bool operator () (query a, query b) {
        if (a.left/SQRT_SIZE == b.left/SQRT_SIZE){
            return a.right < b.right;
        }
        return a.left < b.left;
    }
} queries[MAXQ], cmp; //cmp faster

/*bool cmp(query a, query b) { //cmp slower
    if (a.left/SQRT_SIZE == b.left/SQRT_SIZE){
        return a.right < b.right;
    }
    return a.left < b.left;
}*/

ll arr[MAXN], freq[BIG], ans[MAXQ];

void add(int i, ll &res){
    res += 2 * freq[arr[i]] * arr[i] + arr[i];
    freq[arr[i]]++;
}

void remove(int i, ll &res){
    freq[arr[i]]--;
    res -= 2 * freq[arr[i]] * arr[i] + arr[i];
}

int main(){
    int N, Q;
    scanf(" %d %d", &N, &Q);
    for (int i=1; i<=N; i++){
        scanf(" %I64d", &arr[i]);
    }

    SQRT_SIZE = sqrt(N);
    for (int i=0; i<Q; i++){
        scanf(" %d %d", &queries[i].left, &queries[i].right);
        queries[i].id = i;
    }
    //sort(queries, queries+Q); //slower
    sort(queries, queries+Q, cmp);

    int l = 0;
    int r = -1;
    ll actual = 0;

    for (int i=0; i<Q; i++){
        while (l < queries[i].left){
            remove(l++, actual);
        }

        while (l > queries[i].left){
            add(--l, actual);
        }

        while (r < queries[i].right){
            add(++r, actual);
        }

        while (r > queries[i].right){
            remove(r--, actual);
        }

        ans[queries[i].id] = actual;
    }

    for (int i=0; i<Q; i++){
        printf("%I64d\n", ans[i]);
    }

    return 0;
}
