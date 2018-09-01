#include <bits/stdc++.h>

using namespace std;

const int MAXN = 35555;

int arr[MAXN], freq[MAXN];

int gcd(int a, int b) {
    return (b==0) ? a : gcd(b, a%b);
}

bool solve(const int m, const int n){
    memset(freq, 0, sizeof freq);

    for (int i=0; i<n; i++) {
        freq[arr[i]%m]++;
        //cout << arr[i] << " % " << m << " = " << (arr[i]%m) <<endl;
    }

    for (int i=1; i<m; i++) {
        if (freq[i] != freq[i-1])
            return false;
    }
    return true;
}



int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        scanf(" %d", &arr[i]);
    }

    for (int m=2; m<35000; m++) {
        if (solve(m, N)){
            printf("%d\n", m);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}
