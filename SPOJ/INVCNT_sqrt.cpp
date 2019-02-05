#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 100;
const int SQRT = sqrt(MAXN) + 1;

pair<int, int> input[MAXN];
bool arr[MAXN];
int block[SQRT];

long long int query(int left, int right) {
    long long int total = 0;
    while (left <= right) {
        if ((left % SQRT == 0) && (left + SQRT <= right)) {
            total += block[left / SQRT];
            left  += SQRT;
        } else {
            total += arr[left];
            left++;
        }
    }
    return total;
}

void insert(int idx) {
    arr[idx] = true;
    block[idx / SQRT]++;
}

int main() {
    int testcases;
    scanf(" %d", &testcases);

    for (int test = 0; test < testcases; test++) {
        memset(input, 0, sizeof input);
        memset(arr, 0, sizeof arr);
        memset(block, 0, sizeof block);

        int N;
        scanf(" %d", &N);

        for (int i = 1; i <= N; i++) {
            scanf(" %d", &input[i].first);
            input[i].second = i;
        }

        sort(input + 1, input + N + 1);

        long long int inversions = 0;
        for (int i = 1; i <= N; i++) {
            int idx = input[i].second;
            inversions += query(idx + 1, N);
            //fprintf(stderr, "adicionando %d: %d inversoes\n", input[i].first, query(idx + 1, N));
            insert(idx);
        }

        printf("%lld\n", inversions);
    }


    return 0;
}
