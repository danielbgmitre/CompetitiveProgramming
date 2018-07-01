#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 123;

long long int sequence[MAXN];

int main(){
    int N, K;
    scanf(" %d %d", &N, &K);

    for (int i=0; i<N; i++){
        scanf(" %lld", &sequence[i]);
    }

    sort(sequence, sequence+N);


    if (K == 0){
        if (sequence[0] == 1){
            printf("-1\n");
        } else {
            printf("1\n");
        }
    } else if (sequence[K] == sequence[K-1]){
        printf("-1\n");
    } else {
        printf("%lld\n", sequence[K-1]);
    }

    return 0;
}
