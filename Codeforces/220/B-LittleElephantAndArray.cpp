//http://codeforces.com/problemset/problem/220/B
// Little Elephant and Array - solucao com SQRT Decomposition

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXQ = 1e5 + 10;
const int MAX_SQRT = sqrt(MAXN) + 10;

int SQRT = MAX_SQRT;

struct query {
    int left, right, id;
    bool operator () (query a, query b){
        if (a.left/SQRT == b.left/SQRT)
            return a.right < b.right;
        return a.left < b.left;
    }
} queries[MAXQ], cmp;

int arr[MAXN], freq[MAXN], ans[MAXQ];

void add(int i, int &res, int tam){
    if (arr[i] > tam) return;
    if (freq[arr[i]] == arr[i]){
        res--;
    }
    freq[arr[i]]++;
    if (freq[arr[i]] == arr[i]){
        res++;
    }
}

void remove(int i, int &res, int tam){
    if (arr[i] > tam) return;
    if (freq[arr[i]] == arr[i]){
        res--;
    }
    freq[arr[i]]--;
    if (freq[arr[i]] == arr[i]){
        res++;
    }
}

int main(){
    int N, M;
    scanf(" %d %d", &N, &M);
    for (int i=0; i<N; i++){
        scanf(" %d", &arr[i]);
    }
    for (int i=0; i<M; i++){
        scanf(" %d %d", &queries[i].left, &queries[i].right);
        queries[i].left--, queries[i].right--;
        queries[i].id = i;
    }
    sort(queries, queries+M, cmp);
    int l = 0;
    int r = -1;
    int actual = 0;
    for (int i=0; i<M; i++){
        while (l < queries[i].left) remove(l++, actual, N);
        while (l > queries[i].left) add(--l, actual, N);
        while (r < queries[i].right) add(++r, actual, N);
        while (r > queries[i].right) remove(r--, actual, N);
        ans[queries[i].id] = actual;
    }

    for (int i=0; i<M; i++){
        printf("%d\n", ans[i]);
    }
}
