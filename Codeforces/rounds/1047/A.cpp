#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf(" %d", &N);

    if (N % 3 != 2) {
        printf("1 1 %d\n", N-2);
    } else {
        printf("1 2 %d\n", N-3);
    }

    return 0;
}
