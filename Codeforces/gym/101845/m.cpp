#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N, K;    //confused N and M, so changed order
    scanf(" %d %d %d", &M, &N, &K);

    double prob = 0.0;

    if (K <= N){   // fill K-1 with blue
        N -= K-1;
        prob = (K-1);
        prob += ((double)(N)) / ((double) (N+M));
    } else {       // spend all blue
        prob = (double) (N);
    }

    prob /= (double) (K);

    printf("%.15lf\n", prob);
    return 0;
}
