#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf(" %d", &N);

    long long int x, y, temp, maior=0;
    for (int i=0; i<N; i++) {
        scanf(" %lld %lld", &x, &y);
        temp = x+y;

        if (temp > maior) {
            maior = temp;
        }
    }

    printf("%lld\n", maior);

    return 0;
}
