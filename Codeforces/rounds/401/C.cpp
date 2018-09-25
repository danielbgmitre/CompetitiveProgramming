#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

void solve(int ones, int zeroes, int last1=-1, int last2=-1) {
    if (ones == 0 && zeroes == 0) return;

    if (ones >= zeroes && (last1 != 1 || last2 != 1)) {
        putchar('1');
        solve(ones-1, zeroes, 1, last1);
    } else {
        putchar('0');
        solve(ones, zeroes-1, 0, last1);
    }
}

int main() {
    int zeroes, ones;
    scanf(" %d %d", &zeroes, &ones);

    if (ones + 1 < zeroes) {
        printf("-1\n");
        return 0;
    }

    if (zeroes * 2 < ones - 2) {
        printf("-1\n");
        return 0;
    }

    solve(ones, zeroes);
    putchar('\n');

    return 0;
}
