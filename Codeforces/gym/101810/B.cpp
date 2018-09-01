#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

long long int cookies[MAXN];

int main() {
    int T;
    scanf(" %d", &T);

    for (int test=0; test<T; test++) {
        for (int i=0; i<MAXN; i++) cookies[i] = 0LL;

        long long int x;
        int n;
        scanf(" %llu %d", &x, &n);

        if (n == 1) {
            printf("%llu\n", x);
            continue;
        }

        long long int equal_part_of_cookies = x / (n - 1);
        for (int i=1; i<n; i++) {
            cookies[i] = equal_part_of_cookies;
        }

        x = x % (n-1);

        cookies[n] = cookies[1]/2;
        cookies[1] -= cookies[n];

        int curr_idx;
        if (cookies[1] == cookies[n]) {   // start from left
            curr_idx = 1;
        } else {    // start from left
            curr_idx = n;
        }

        int step = 1;
        while (x > 0) {
            if (curr_idx == 1){
                step = 1;
            }
            if (curr_idx == n){
                step = -1;
            }

            cookies[curr_idx]++;

            curr_idx += step;
            x--;
        }

        for (int i=1; i<=n; i++) {
            printf("%lld", cookies[i]);
            if (i < n) printf(" ");
        }
        printf("\n");
    }


    return 0;
}
