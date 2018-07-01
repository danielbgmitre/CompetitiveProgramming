#include <bits/stdc++.h>

using namespace std;

char lines[2][111];

int main() {
    scanf(" %s", lines[0]);
    scanf(" %s", lines[1]);

    size_t tam = strlen(lines[0]);
    for (size_t i=0; i<tam; i++){
        lines[0][i] = (lines[0][i] == '0');
        lines[1][i] = (lines[1][i] == '0');
    }

    int res = 0;
    for (size_t i=0; i<tam; i++){
        bool matched = false;
        if (i+2 < tam) {
            if (lines[0][i] && lines[0][i+1] && lines[0][i+2]
             && lines[1][i] && lines[1][i+1] && lines[1][i+2]) {
                 res += 2;
                 i += 2;
                 matched = true;
             }
        }
        if (!matched && i+1 < tam){
            if (lines[0][i] && lines[1][i]) {
                if (lines[0][i+1] || lines[1][i+1]) {
                    res++;
                    i++;
                }
            } else if (lines[0][i+1] && lines[1][i+1]) {
                if (lines[0][i] || lines[1][i]) {
                    res++;
                    i++;
                }
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
