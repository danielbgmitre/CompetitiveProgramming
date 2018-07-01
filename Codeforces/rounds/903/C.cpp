//http://codeforces.com/contest/903/problem/C
//Boxes Packing

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5050;

int boxes[MAXN];
bitset<MAXN> used, full;

int main(){
    int N; scanf(" %d", &N);
    for (int i=0; i<N; i++){
        scanf(" %d", &boxes[i]);
    }

    sort(boxes, boxes+N);

    int res = N;
    for (int i=0; i<N; i++){
        if (used[i]) continue;

        for (int j=i+1; j<N; j++){
            if (full[j] || boxes[i] == boxes[j]) continue;
            used[i] = 1;
            full[j] = 1;
            res -= 1;
            break;
        }
    }
    printf("%d\n", res);

    return 0;
}
