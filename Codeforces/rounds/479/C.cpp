#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5050;

pair<int, int> exams[MAXN];

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        scanf(" %d %d", &exams[i].first, &exams[i].second);
    }

    sort(exams, exams+N);

    int curr_day = exams[0].second;
    for (int i=0; i<N; i++) {
        if (curr_day > exams[i].second) {
            curr_day = exams[i].first;
        } else {
            curr_day = min(exams[i].first, exams[i].second);
        }
    }

    printf("%d\n", curr_day);

    return 0;
}
