#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 100;

int N;

char arr[MAXN];
int pi[MAXN];

void prefix_function() {
    for (int i = 1; i < N; i++) {
        int j = pi[i-1];
        while (j > 0 && arr[i] != arr[j])
            j = pi[j-1];
        if (arr[i] == arr[j])
            j++;
        pi[i] = j;
    }
}


int main() {
    scanf(" %d", &N);

    for (int i=0; i<N; i++){
        scanf(" %c", &arr[i]);
    }

    prefix_function();

    bool ugly = true;

    for (int i=1; i<N; i++) {
        if (pi[i] > 1 && arr[i] < arr[pi[i-pi[i]]]) {
            ugly = false;
        }
        if (arr[i] < arr[pi[i-1]]) {
            ugly = false;
        }
    }

    bool temDiferentes = false;
    for (int i=1; i<N; i++) {
        if (arr[i] != arr[i-1]) temDiferentes = true;
    }

    if (temDiferentes && N > 1 && arr[0] == arr[N-1]) {
        ugly = false;
    }

    if (!ugly){
        printf("No\n");
    } else {
        printf("Yes\n");
    }



    return 0;
}
