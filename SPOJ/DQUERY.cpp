//http://www.spoj.com/problems/DQUERY/
//DQUERY - solucao com Mo's Algorithm

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e4 + 10;
const int MAXQ = 2e5 + 10;
//numero magico: 1.514

int SQRT_SIZE = sqrt(MAXN);

struct query{
    int left, right, id;

    bool operator < (const query (&other)) const {
        if (left/SQRT_SIZE == other.left/SQRT_SIZE){
            return right < other.right;
        }
        return left < other.left;
    }
} queries[MAXQ];

int sequence[MAXN], ans[MAXQ], freq[1001001];

int main(){
    int N;
    scanf(" %d", &N);
    for (int i=0; i<N; i++){
        scanf(" %d", &sequence[i]);
    }
    SQRT_SIZE = sqrt(N);

    int Q;
    scanf(" %d", &Q);
    for (int i=0; i<Q; i++){
        scanf(" %d %d", &queries[i].left, &queries[i].right);
        queries[i].left--; queries[i].right--;
        queries[i].id = i;
    }
    sort(queries, queries+Q);

    int l = 0;
    int r = -1;
    int actual = 0;

    for (int i=0; i<Q; i++){
        while (l < queries[i].left){
            if (freq[sequence[l]] == 1){
                actual--;
            }
            freq[sequence[l++]]--;
        }

        while (l > queries[i].left){
            if (freq[sequence[--l]] == 0){
                actual++;
            }
            freq[sequence[l]]++;
        }

        while (r < queries[i].right){
            if (freq[sequence[++r]] == 0){
                actual++;
            }
            freq[sequence[r]]++;
        }

        while (r > queries[i].right){
            if (freq[sequence[r]] == 1){
                actual--;
            }
            freq[sequence[r--]]--;
        }

        ans[queries[i].id] = actual;
    }

    for (int i=0; i<Q; i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}
