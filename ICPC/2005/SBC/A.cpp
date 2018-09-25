#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-5;

inline bool is_zero(double p) {
    return -eps < p && p < eps;
}

int main() {
    double V;
    int N, M;
    while (scanf("%lf %d %d", &V, &N, &M) && !(M == 0 && N == 0 && is_zero(V))) {
        if (N%10000 == M%10000) {
            V *= 3000;
        } else if (N%1000 == M%1000) {
            V *= 500;
        } else if (N%100 == M%100) {
            V *= 50;
        } else {
            N %= 100;
            if (N==0) N = 100;
            M %= 100;
            if (M==0) M = 100;
            N--, M--;
            if (N/4 == M/4) {
                V *= 16;
            } else {
                V *= 0;
            }
        }
        printf("%.2f\n", V);
    }

    return 0;
}
