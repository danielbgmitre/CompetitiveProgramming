//http://www.spoj.com/problems/RACETIME/
//RACETIME - solucao com SQRT Decomposition

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAX_SQRT = sqrt(MAXN) + 10;

int SQRT = MAX_SQRT;

typedef vector<int> vi;

int v[MAXN];
vi cows[MAX_SQRT];

int query(int left, int right, int x){
    int res = 0;
    vi::iterator up;
    while (left <= right){
        if (left%SQRT==0 && left+SQRT-1 <= right){
            int block = left/SQRT;
            up = upper_bound(cows[block].begin(), cows[block].end(), x);
            res += up - cows[block].begin();
            left += SQRT;
        } else {
            if (v[left] <= x){
                res++;
            }
            left++;
        }
    }
    return res;
}

void update(int pos, int value){
    int block = pos/SQRT;
    int i = lower_bound(cows[block].begin(), cows[block].end(), v[pos])-cows[block].begin();
    cows[block][i] = value;
    sort(cows[block].begin(), cows[block].end());
    v[pos] = value;
}

int main(){
    int N, Q;
    scanf(" %d %d", &N, &Q);
    SQRT = sqrt(N);

    for(int i=0; i<N; i++){ //recebe vaquinhas
        scanf(" %d", &v[i]);
        cows[i/SQRT].push_back(v[i]);
    }

    for (int i=0; i<=N/SQRT; i++){  //ordena vaquinhas
        sort(cows[i].begin(), cows[i].end());
    }

    char op;
    int p, q, x;
    for (int i=0; i<Q; i++){    //recebe perguntas
        scanf(" %c", &op);
        switch (op) {
            case 'M':
                scanf(" %d %d", &p, &x);
                update(p-1, x);
                break;
            case 'C':
                scanf(" %d %d %d", &p, &q, &x);
                printf("%d\n", query(p-1, q-1, x));
                break;
        }

    }

    return 0;
}
