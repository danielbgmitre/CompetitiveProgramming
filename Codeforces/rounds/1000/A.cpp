#include <bits/stdc++.h>

using namespace std;

string o_shirts[111];
string n_shirts[111];

vector<string> velho, novo;

int main() {
    int N;
    scanf(" %d", &N);
    velho.resize(N); novo.resize(N);

    char temp[10];
    for (int i=0; i<N; i++) {
        scanf(" %s", temp);
        velho[i] = temp;
    }

    for (int i=0; i<N;cd g i++) {
        scanf(" %s", temp);
        novo[i] = temp;
    }

    int iguais = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (velho[i] == novo[j]) {
                iguais++;
                velho[i] = novo[j] = "";
                break;
            }
        }
    }

    printf("%d\n", N-iguais);



    return 0;
}
