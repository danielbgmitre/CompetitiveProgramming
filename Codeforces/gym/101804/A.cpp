#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf(" %d", &N);

    int temp, curr = 0, menor = 0;
    for (int i=0; i<N; i++) {
        scanf(" %d", &temp);
        curr += temp;
        menor = min(menor, curr);
    }

    printf("%d\n", -menor);

    return 0;
}
