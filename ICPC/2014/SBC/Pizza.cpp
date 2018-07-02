#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int azeitonas[MAXN];
int positions[MAXN];

int main() {
    int C, N;
    scanf(" %d %d", &C, &N);
    assert(C >= 3 && N >= 3);

    int size = C/N;
    assert(size*N == C);

    for (int i=0; i<N; i++) {
        scanf(" %d", &positions[i]);
        azeitonas[positions[i]] = 1;
        assert(positions[i] >= 0 && positions[i] < C);
    }
    azeitonas[positions[0]+C] = 1;

    for (int i=1; i<MAXN; i++) azeitonas[i] += azeitonas[i-1];

    bool possible = false;
    for (int i=positions[0]; i<positions[1]; i++) {
        if (possible) break;
        possible = true;
        //cout << "testando para comecando em "<<i<<endl;
        int line = i;
        for (int qtd=1; qtd<=N; qtd++) {
            int how_many = azeitonas[i + (size * (qtd-1))];
            assert(line == i+(size*(qtd-1)));
            //cout << "tem "<< how_many << " antes de "<<line<<endl;
            if (!(how_many == qtd)) {
                //cout << "esperado: "<<qtd<<endl;
                possible = false;
            }
            line += size;
        }
        assert(line%C == i);

    }

    printf((possible) ? "S\n" : "N\n");

    return 0;
}
