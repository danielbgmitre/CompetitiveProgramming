#include <bits/stdc++.h>

using namespace std;

int grade[111];

int main() {
    int N;
    scanf(" %d", &N);

    int total = 0;
    for (int i=0; i<N; i++) {
        scanf(" %d", &grade[i]);
        total += grade[i];
    }

    sort(grade, grade+N);

    int extra = 0;
    while (round(total/(double) (N)) < 5){
        total -= grade[extra];
        total += 5;
        extra++;
    }
    printf("%d\n", extra);

    return 0;
}
