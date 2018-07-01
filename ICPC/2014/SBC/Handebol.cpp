#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    scanf(" %d %d", &N, &M);

    int res = 0;
    for (int i=0; i<N; i++) {
        bool perfect = true;
        int temp;
        for (int match=0; match<M; match++){
            scanf(" %d", &temp);
            if (!temp) perfect = false;
        }
        res += perfect;
    }
    printf("%d\n", res);

    return 0;
}
