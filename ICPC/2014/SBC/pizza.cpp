#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int azeitonas[MAXN];

int main() {
    int C, N;
    scanf(" %d %d", &C, &N);

    for (int i=1; i<=N; i++) {
        scanf(" %d", &azeitonas[i]);
    }
    azeitonas[N+1] = C + azeitonas[1];
    azeitonas[N+2] = C + azeitonas[2];

    int tam = C/N;

    bool possible = true;
    for (int i=1; i<=N; i++) {
        int dist1 = azeitonas[i+1] - azeitonas[i];
        int dist2 = azeitonas[i+2] - azeitonas[i+1];
        if (dist1 > tam && dist2 > tam) {
            possible = false;
        }
    }

    printf((possible) ? "S\n" : "N\n");

    return 0;
}
