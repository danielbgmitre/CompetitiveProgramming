#include <bits/stdc++.h>

using namespace std;

int grundy[111];
int game[111];



int main () {
    int N;
    scanf(" %d", &N);

    char temp;
    for (int i=0, i<N; i++) {
        scanf(" %c", &temp);
        game[i] = temp - '0';
    }


    return 0;
}
