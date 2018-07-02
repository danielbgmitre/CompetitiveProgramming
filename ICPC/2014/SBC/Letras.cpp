#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;

char parque[MAXN][MAXN];

bool bit(int number, int bit) {
    return number & (1<<bit);
}

struct state {
    int x, y, dist;
    state () : x(0), y(0), dist(0) {}
    state(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isValid(int x, int y, int N, int mask) {
    if (x < 0 || x >= N) return false;
    if (y < 0 || y >= N) return false;

    signed char letra = parque[x][y];
    //cout << "checando letra: "<<parque[x][y]<<endl;
    if (letra-'a' >= 0)
        return !bit(mask, letra-'a');
    return bit(mask, letra-'A');
}

int bfs(const int N, int mask) {
    bitset<MAXN> visited[N];
    queue<state> fila;
    if (isValid(0, 0, N, mask)) fila.push({0, 0, 1});
    visited[0][0] = 1;

    while (!fila.empty()) {
        int x = fila.front().x;
        int y = fila.front().y;
        int dist = fila.front().dist;
        fila.pop();

        if (x == N-1 && y == N-1) return dist;
        visited[x][y] = 1;

        if (isValid(x-1, y, N, mask) && !visited[x-1][y])
            fila.push({x-1, y, dist+1});
        if (isValid(x, y-1, N, mask) && !visited[x][y-1])
            fila.push({x, y-1, dist+1});
        if (isValid(x+1, y, N, mask) && !visited[x+1][y])
            fila.push({x+1, y, dist+1});
        if (isValid(x, y+1, N, mask) && !visited[x][y+1])
            fila.push({x, y+1, dist+1});
    }

    return INT_MAX;
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf(" %c", &parque[i][j]);
        }
    }

    int dist = INT_MAX;
    for (int mask=0; mask<1024; mask++) {
        dist = min(dist, bfs(N, mask));
    }

    if (dist == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", dist);
    }

    return 0;
}
