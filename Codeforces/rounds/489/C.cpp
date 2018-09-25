#include <bits/stdc++.h>

using namespace std;

const int MAXM = 111;

char digits[MAXM];

void createSmallest(int N, int sum) {
    for (int i=0; i<N && sum; i++) {
        digits[i] = 0;
    }

    digits[0]++;
    sum--;

    for (int i=N-1; i>=0; i--) {
        while (digits[i] < 9 && sum) {
            digits[i]++;
            sum--;
        }
    }
}

void createLargest(int N, int sum) {
    for (int i=0; i<N && sum; i++) {
        digits[i] = 0;
    }

    for (int i=0; i<N; i++) {
        while (digits[i] < 9 && sum) {
            digits[i]++;
            sum--;
        }
    }
}

int main() {
    int M, S;
    scanf(" %d %d", &M, &S);

    if (M == 1 && S == 0) {
        printf("0 0\n");
        return 0;
    }

    if (S < 1 || S > 9 * M) {
        printf("-1 -1\n");
        return 0;
    }

    createSmallest(M, S);
    for (int i=0; i<M; i++) {
        putchar('0' + digits[i]);
    }
    putchar(' ');

    createLargest(M, S);
    for (int i=0; i<M; i++) {
        putchar('0' + digits[i]);
    }
    putchar('\n');


    return 0;
}
