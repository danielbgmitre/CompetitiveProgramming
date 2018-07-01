#include <bits/stdc++.h>

using namespace std;

const int MAXBITMASK = 1<<19;
const int INF = 99999999;

bool QRCodes[19][21][21], reset[19][19];
int restarting[19], dists[19][19], dp[19][MAXBITMASK], camefrom[MAXBITMASK];

int salesman(int current, int parent, int restart_time, int N) {
    if (dp[current][parent] == -1) {
        if (!parent) {
            dp[current][parent] = dists[18][current];
            //cout << "gastei "<<dp[current][parent]<<"ms em "<<(current+1)<<endl;
        } else {
            dp[current][parent] = INF;
            for (int bit=0; bit<N; bit++){
                int real_bit = 1<<bit;
                if (parent & real_bit) {
                    int new_dist = dists[bit][current]
                        + salesman(bit, parent - real_bit, restart_time, N);
                    if (new_dist < dp[current][parent]){
                        dp[current][parent] = new_dist;
                        camefrom[parent] = parent-real_bit;
                    }
                }
            }
        }
    }
    return dp[current][parent];
}

int differs(int QRa, int QRb){
    int total = 0;
    for (int i=0; i<21; i++){
        for (int j=0; j<21; j++){
            total += (QRCodes[QRa][i][j] != QRCodes[QRb][i][j]);
        }
    }
    return total;
}

int main() {
    int N, restart_time;
    scanf(" %d %d", &N, &restart_time);

    char temp;
    for (int i=0; i<N; i++){
        restarting[i] = restart_time;
        for (int lin=0; lin<21; lin++){
            for (int col=0; col<21; col++) {
                scanf(" %c", &temp);
                QRCodes[i][lin][col] = (temp == '1');
                restarting[i] += QRCodes[i][lin][col];
            }
        }
    }

    for (int from=0; from<N; from++){
        for (int to=0; to<N; to++) {
            if (from == to) continue;
            int without_restart = differs(from, to);
            if (restarting[to] < without_restart) {
                reset[from][to] = true;
            }
            dists[from][to] = min(
                without_restart,
                restarting[to]
            );
        }
        dists[18][from] = restarting[from]-restart_time;
    }

    for (int i=0; i<19; i++) {
        for (int j=0; j<MAXBITMASK; j++){
            dp[i][j] = -1;
        }
    }

    cout << salesman(18, (1 << N) - 1, restart_time, N) << endl;
    int bitmask = (1 << N) - 1;
    int from = 18;

    int curr;
    while (bitmask) {
        curr = camefrom[bitmask] ^ bitmask;
        for (int bit=0; bit<N; bit++){
            if (curr & (1<<bit)) curr=bit;
        }
        if (reset[from][curr]) {
            assert(dists[from][curr] == restarting[curr]);
            printf("*\n");
        }
        printf("%d\n", curr+1);
        from = curr;
        bitmask = camefrom[bitmask];
    }

    return 0;
}
