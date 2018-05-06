#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6e5 + 15;

char res[MAXN];

int main() {
    unsigned long long int N, K;
    scanf(" %llu %llu", &N, &K);

    int pos = 0;
    int deep = 0;
    int unclosed = 0;
    while (N) {
        if (deep > K){
            deep--;
            res[pos++] = ')';
            unclosed--;
        } else {
            K -= deep;
            deep++;
            res[pos++] = '(';
            unclosed++;
            N--;
        }
    }

    if (K){
        printf("Impossible\n");
    } else {
        printf("%s", res);
        for (int i=0; i<unclosed; i++){
            printf(")");
        }
        printf("\n");
    }

    return 0;
}
