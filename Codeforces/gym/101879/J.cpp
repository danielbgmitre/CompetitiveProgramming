#include <bits/stdc++.h>

using namespace std;

char curr = 'z';

char solve(int n) {
    int hi = 67108863;
    int lo = 1;

    while (hi > lo) {
        int mid = (hi+lo) / 2;
        if (mid == n) return curr;
        //cout << mid << endl;
        if (mid > n) {
            hi = mid;
        } else {
            lo = mid;
        }
        curr--;
    }
    return curr;
}

int main() {
    int N;
    scanf(" %d", &N);
    printf("%c\n", solve(N));

    return 0;
}
