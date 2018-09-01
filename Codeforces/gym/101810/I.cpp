#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf(" %d", &T);

    for (int test=0; test<T; test++) {
        int X, N;
        scanf(" %d %d", &X, &N);

        if (N > X) {
            printf("-1\n");
            continue;
        }

        int equal_part = X/N;
        int remaining  = X%N;

        while (N){
            printf("%d ", equal_part + (N<=remaining));
            N--;
        }
        printf("\n");
    }

    return 0;
}
