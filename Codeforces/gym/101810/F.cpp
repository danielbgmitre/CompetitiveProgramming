#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const int MAXA = 1e6 + 10;

int arr[MAXN];
bitset<MAXA> isPrime;
vector<int> primes;

void sieve(int N){
    isPrime.reset();
    primes.clear();

    for (int i=0; i<N; i++) {
        isPrime[arr[i]] = 1;
    }

    for (int i=2; i*i < MAXA; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j=i*2; j*j < MAXA; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

int main() {
    int T;
    scanf(" %d", &T);

    for (int test=0; test<T; test++) {
        int N;
        scanf(" %d", &N);

        for (int i=0; i<N; i++) {
            scanf(" %d", &arr[i]);
        }
        sort(arr, arr+N);

        sieve(N);

        int res = 0;
        for (int i=0; i<N; i++) {
            if (!isPrime[arr[i]]) {
                for (int p : primes) {
                    if ((arr[i] % p) == 0) {
                        arr[i] = p;
                        break;
                    }
                }
            }
            res += arr[i];
        }

        printf("%d\n", res);

    }

    return 0;
}
