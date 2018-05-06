#include <bits/stdc++.h>

using namespace std;

const int MAXN = 256;

class Noise {
public:
    int qtd, lin, col;
    Noise () : qtd(0), lin(0), col(0) {}
    Noise (int qtd, int lin, int col) : qtd(qtd), lin(lin), col(col) {}
};

int mapa[MAXN][MAXN];
vector<Noise> barulhos;

int lin[4] = {-1, 0, 1, 0};
int col[4] = { 0, 1, 0,-1};

void bfs(Noise n, int linhas, int colunas){
    queue<Noise> fila;
    fila.push(n);
    bitset<MAXN> visited[MAXN];

    Noise actual;
    int nLin, nCol, nBarulho;
    while (!fila.empty()){
        actual = fila.front();
        fila.pop();

        visited[actual.lin][actual.col] = 1;
        nBarulho = actual.qtd>>1;
        if (nBarulho == 0) continue;

        for (int i=0; i<4; i++){
            nLin = actual.lin + lin[i];
            nCol = actual.col + col[i];

            if (nLin < 0 || nLin >= linhas) continue;
            if (nCol < 0 || nCol >= colunas) continue;
            if (mapa[nLin][nCol] < 0 || visited[nLin][nCol]) continue;

            visited[nLin][nCol] = 1;
            fila.push({nBarulho, nLin, nCol});
            mapa[nLin][nCol] += nBarulho;
        }
    }
}

int main() {
    int N, M, Q, P;
    scanf(" %d %d %d %d", &N, &M, &Q, &P);

    char temp;
    int t_barulho;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            scanf(" %c", &temp);
            if (temp == '*') {      //*   = obstacle => 0
                mapa[i][j] = -1;
            } else if (temp == '.'){//.   = regular  => 0
                mapa[i][j] = 0;
            } else {                //A-Z = source   => -1
                t_barulho = Q*(temp-'A'+1);
                barulhos.push_back({t_barulho, i, j});
                mapa[i][j] = t_barulho;
            }
        }
    }

    for (int i=0; i<barulhos.size(); i++){
        bfs(barulhos[i], N, M);
    }

    int res = 0;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (mapa[i][j] > P) res++;
        }
    }
    printf("%d\n", res);

    return 0;
}
