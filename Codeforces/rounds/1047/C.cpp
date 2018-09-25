#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;
const int INF = 1.5 * 1e7 + 100;

int number[MAXN];
int freq[INF];

int lp[INF];
vector<int> pr;

void crive() {
    for (int i=2; i<INF; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<INF; ++j){
            lp[i * pr[j]] = pr[j];
        }
    }
}

void mark_divisors(int value) {
    int divisor;
    while (value > 1) {
        divisor = lp[value];
        if (divisor == 0) {
            freq[value]++;
        } else {
            int curr_divisor = divisor;
            while (lp[value] == divisor) {
                value /= divisor;
                freq[curr_divisor]++;
                curr_divisor += divisor;
            }
        }
    }
}

int main() {
    int N;
    scanf(" %d", &N);

    crive();

    for (int i=0; i<N; i++) {
        scanf(" %d", &number[i]);
    }

    for (int i=0; i<N; i++) {
        mark_divisors(number[i]);
    }

    int best = 0;
    for (int i=2; i<INF; i++) {
        int curr_freq = freq[i];
        if (curr_freq < N && best < curr_freq) {
            best = curr_freq;
        }
    }

    if (best == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", N-best);
    }

    return 0;
}
