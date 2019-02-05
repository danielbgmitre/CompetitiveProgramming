#include <bits/stdc++.h>

using namespace std;

#define debug fprintf

const int MAXN = 55;

int arr[MAXN];

void showArr(int n){
    for (int i = 0; i < n; i++){
        debug(stderr, "%d%c", arr[i], " \n"[i == n-1]);
    }
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

inline bool coprime(int a, int b) {
    return gcd(a, b) == 1;
}

bitset<MAXN> vis;

bool conected(size_t n) {
    vis.reset();
    queue<int> fila;
    fila.push(0), vis.set(0);

    int curr;
    while (!fila.empty()) {
        curr = fila.front(); fila.pop();
        for (size_t i=0; i < n; i++) {
            if (!vis[i] && coprime(arr[curr], arr[i])) {
                vis.set(i), fila.push(i);
            }
        }
    }

    return vis.count() == n;
}

int changed;
void solve(size_t n) {
    changed = 0;
    while (!conected(n)) {
        changed++;
        bool use47 = false;
        for (int i=0; i<n; i++) {
            if (vis[i] && arr[i] == 43) {
                use47 = true;
            }
        }
        bool done = false;
        for (int i=0; i<n && !done; i++) {
            if (!vis[i]) {
                done = true;
                if (use47) {
                    arr[i] = 47;
                } else {
                    arr[i] = 43;
                }
            }
        }
        //showArr(n);
    }
}

int main() {
    int T;
    scanf(" %d", &T);

    for (int t = 0; t < T; t++) {
        int N;
        scanf(" %d", &N);

        for (int i=0; i<N; i++) {
            scanf(" %d", &arr[i]);
        }

        //debug(stderr, "is connected? %d\n", conected(N));
        solve(N);

        printf("%d\n", changed);
        for (int i = 0; i < N; i++){
            printf("%d%c", arr[i], " \n"[i == N-1]);
        }
    }


    return 0;
}
