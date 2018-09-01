#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int arr[MAXN];
int freq[101];
int res[MAXN];

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        scanf(" %d", &arr[i]);
    }

    for (int i=0; i<101; i++) {
        freq[i] = MAXN;
    }

    for (int i=N-1; i>=0; i--) {
        int value = MAXN;
        for (int v=arr[i]+1; v<101; v++) {
            if (freq[v] < value) {
                value = freq[v];
            }
        }
        if (value == MAXN) {
            res[i] = -1;
        } else {
            res[i] = arr[value];
        }
        freq[arr[i]] = i;
    }


    for (int i=0; i<N; i++) {
        if (res[i] == -1) printf("*");
        else printf("%d", res[i]);

        if (i<N-1) printf(" ");
        else printf("\n");
    }

    return 0;
}
