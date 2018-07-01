#include <bits/stdc++.h>

using namespace std;

struct plane {
    int a, b, c, d;
    bool above(int x, int y, int z) {
        return a*x + b*y + c*z > d;
    }
};

const int MAXM = 555;

plane planes[MAXM];
unordered_map<bitset<MAXM>, int> regions;

int main() {
    int M, N;
    scanf(" %d %d", &M, &N);

    for (int i=0; i<M; i++){
        scanf(" %d %d %d %d", &planes[i].a,
                              &planes[i].b,
                              &planes[i].c,
                              &planes[i].d);
    }

    int x, y, z;
    for (int i=0; i<N; i++) {
        scanf(" %d %d %d", &x, &y, &z);
        bitset<MAXM> mask;
        for (int j=0; j<M; j++){
            mask[j] = planes[j].above(x, y, z);
        };
        regions[mask]++;
    }

    int best = 0;
    for (auto p : regions){
        best = max(best, p.second);
    }
    printf("%d\n", best);


    return 0;
}
