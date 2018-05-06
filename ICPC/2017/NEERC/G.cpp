#include <bits/stdc++.h>

using namespace std;

int results[7];

int main() {
    int N;
    scanf(" %d", &N);

    char temp;
    for (int i=0; i<N; i++){
        for (int j=0; j<7; j++){
            scanf(" %c", &temp);
            results[j] += temp-'0';
        }
    }

    int res = 0;
    for (int i=0; i<7; i++) {
        res = max(res, results[i]);
    }
    printf("%d\n", res);

    return 0;
}
