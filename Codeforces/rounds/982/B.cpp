#include <bits/stdc++.h>

using namespace std;

pair<int, int> sizes[210012];

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        scanf(" %d", &sizes[i].first);
        sizes[i].second = i+1;
    }
    sort(sizes, sizes+N);

    int curr = 0;
    stack<int> pilha;

    char temp;
    for (int i=0; i<N*2; i++) {
        scanf(" %c", &temp);
        if (temp == '0'){
            printf("%d ", sizes[curr].second);
            pilha.push(sizes[curr++].second);
        } else {
            printf("%d ", pilha.top());
            pilha.pop();
        }
    }
    printf("\n");

    return 0;
}
