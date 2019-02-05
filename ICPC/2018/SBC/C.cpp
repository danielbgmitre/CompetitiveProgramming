/*
 * Cheap Trips
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2905
 * O(N) solution
 */

#include <bits/stdc++.h>

using namespace std;

struct trip {
    int duration;
    double price;
    trip() : duration(0), price(0) {}
};

const int MAXN = 1e6 + 111;

trip trips[MAXN];
double dp[MAXN];

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=1; i <= N; i++) {
        scanf(" %d %lf", &trips[i].duration, &trips[i].price);
        dp[i] = 99999999;
    }

    for (int i=1; i <= N; i++) {
        double price = trips[i].price;
        int duration = trips[i].duration;
        dp[i] = min(dp[i], dp[i-1] + trips[i].price);

        if (duration < 120) {
            dp[i+1] = min(dp[i+1], dp[i-1] + price + (0.5 * trips[i+1].price));
        }

        double sum = 0;
        for (int j=1; j<5; j++) {
            duration += trips[i+j].duration;
            sum += trips[i+j+1].price;
            if (duration < 120) {
                dp[i+j+1] = min(dp[i+j+1],
                    dp[i-1]
                    + price
                    + (0.5 * trips[i+1].price)
                    + (0.25 * sum)
                );
            }
        }
    }

    printf("%.2lf\n", dp[N]);

    return 0;
}
