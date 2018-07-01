#include <bits/stdc++.h>

using namespace std;

char seat[1221];

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++){
        scanf(" %c", &seat[i]);
        seat[i] -= '0';
    }

    bool maximal = true;
    if (N > 1){
        if (!seat[0] && !seat[1]) maximal = false;
        if (!seat[N-1] && !seat[N-2]) maximal = false;
    }

    int sequence = 0;
    for (int i=1; i<N; i++){
        (!seat[i]) ? sequence++ : sequence = 0;
        if (sequence >= 3) maximal = false;
        if (seat[i] && seat[i-1]) maximal = false;
    }

    if (N == 1 && !seat[0]) maximal = false;

    printf(maximal? "Yes\n" : "No\n");

    return 0;
}
