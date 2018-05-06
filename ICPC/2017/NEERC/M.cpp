#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf(" %d", &N);

    int a, b;
    scanf(" %d %d", &a, &b);

    int delta = b-a;

    for (int i=0; i<N-2; i++) {
        scanf(" %d", &a);
        if (a != b+delta) delta = 0;

        swap(a, b);
    }

    printf("%d\n", b+delta);

    return 0;
}
