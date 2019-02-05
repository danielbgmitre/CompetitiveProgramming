#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

char hats[MAXN];

int main() {
    int N = 0;

    int left = 0, right = 0;
    while (~scanf(" %c", &hats[N])){
        hats[N] -= '0';
        left ^= hats[N];
        N++;
    }

    for (int i=N-1; i>=0; i--) {
        left ^= hats[i];
        if (hats[i] != (left ^ right)) {
            printf("NO\n");
            return 0;
        }
        right ^= hats[i];
    }

    printf("YES\n");

    return 0;
}
