#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 10;

long long int arr[MAXN];
vector<int> idx1, idx2;

int main() {
    int N;
    scanf(" %d", &N);

    long long int total = 0;
    for (int i=1; i<=N; i++) {
        scanf(" %lld", &arr[i]);
        total += arr[i];
    }

    // impossible
    if (total % 3LL) {
        printf("0\n");
        return 0;
    }

    long long first = total / 3;
    long long second = 2 * first;

    long long int curr = 0;
    for (int i=1; i<N; i++) {
        curr += arr[i];
        if (curr == first) {
            idx1.push_back(i);
        }
        if (curr == second) {
            idx2.push_back(i);
        }
    }

    int a = 0;
    int b = 0;

    long long int res = 0;
    while (a < idx1.size() && b < idx2.size()) {
        if (idx1[a] < idx2[b]) {
            a++;
            res += idx2.size() - b;
        } else {
            b++;
        }
    }

    printf("%lld\n", res);

    return 0;
}
