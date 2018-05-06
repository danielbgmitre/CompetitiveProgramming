#include <bits/stdc++.h>

using namespace std;

const int MAXN = 123321;

int values[MAXN], changed[MAXN];

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++){
        scanf(" %d", &values[i]);
    }

    changed[0] = values[0];
    for (int i=1; i<N; i++){
        changed[i] = max(values[i], changed[i-1]+1);
    }

    changed[N-1] = values[N-1];
    int stopped_at = N-1;
    for (int i=N-2; i>=0; i--){
        if (changed[i+1]+1 >= changed[i]){
            stopped_at = i;
            break;
        } else {
            changed[i] = max(changed[i+1]+1, values[i]);
        }
    }

    long long int res = 0;
    for (int i=0; i<N; i++){
        res += changed[i]-values[i];
    }
    if (changed[stopped_at] == changed[stopped_at+1]){
        res++;
    }
    printf("%lld\n", res);

    return 0;
}
