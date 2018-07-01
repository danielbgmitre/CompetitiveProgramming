#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, D;
    scanf(" %d %d %d %d", &A, &B, &C, &D);

    bool some_error = false;
    if (A < C || B < C) {
        some_error = true;
    } else {
        A -= C;
        B -= C;
        if (A + B + C >= D) {
            some_error = true;
        } else {
            printf("%d\n", D - (A+B+C));
        }
    }

    if (some_error) {
        printf("-1\n");
    }

    return 0;
}
