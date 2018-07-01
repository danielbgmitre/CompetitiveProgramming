#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; scanf(" %d", &N);
    int half = N/2;

    int current_pos = 1;
    int res = 0;


    while (1) {
        if (current_pos <= half) {
            current_pos *= 2;
        } else {
            current_pos = (current_pos - half - 1) * 2 + 1;
        }
        res++;
        if (current_pos == 1) break;
    }

    printf("%d\n", res);

    return 0;
}
