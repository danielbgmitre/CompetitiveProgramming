//https://www.urionlinejudge.com.br/judge/pt/problems/view/1330
//A Terra Herdada por Tio Tom

#include <bits/stdc++.h>

using namespace std;

class MaxMatching {
public:
    unsigned int tamA, tamB;
    vector<vector<int>> grupoA;
    vector<int> grupoB;
    vector<bool> vis;

    bool find(int v) {
        if (vis[v]) return false;

        vis[v] = true;
        for (size_t i=0; i<grupoA[v].size(); i++){
            int to = grupoA[v][i];
            if (grupoB[to] == -1 || find(grupoB[to])){
                grupoB[to] = v;
                return true;
            }
        }
        return false;
    }

    void init(int x, int y) {
        tamA = x; tamB = y;
        grupoA.assign(tamA+1, vector<int>(0));
    }

    void insert(int from, int to) {
        grupoA[from].push_back(to);
    }

    int matchings() {
        int res = 0;
        grupoB.assign(tamB+1, -1);
        for (size_t i=0; i<tamA; i++){
            vis.assign(tamA+1, false);
            if (find(i)) res++;
        }
        return res;
    }
};

int terra[101][101];
int tamA=0, tamB=0;

map<pair<int, int>, int> parser;

void zera(){
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            terra[i][j] = 1;
        }
    }
}

int cod(int x, int y){
    if (parser.count({x, y})){
        return parser[{x, y}];
    }
    return parser[{x, y}] = ((x+y)%2)? tamA++: tamB++;
}

bool inRange(int n, int lower, int upper){
    return (n >= lower && n <= upper);
}


int moveL[] = {-1, 0, 1, 0};
int moveC[] = {0, -1, 0, 1};
MaxMatching matcher = MaxMatching();

int main(){
    //freopen("1330.out", "w", stdout);
    int N, M;
    while (scanf(" %d %d", &N, &M) && N+M > 0){
        zera(); tamA = tamB = 0;
        parser.clear();
        int K; scanf(" %d", &K);

        int x, y;
        for (int i=0; i<K; i++){
            scanf(" %d %d", &x, &y);
            terra[x][y] = 0;
        }

        for (int i=1; i<=N; i++){
            for (int j=0; j<=M; j++){
                if (terra[i][j]){
                    ((i+j)%2)? tamA++ : tamB++;
                }
            }
        }

        matcher.init(tamA, tamB);
        tamA = tamB = 0;

        for (int i=1; i<=N; i++){
            for (int j=1; j<=M; j++){
                if (terra[i][j] && (i+j)%2){
                    for (int t=0; t<4; t++){
                        if (inRange(i+moveL[t], 1, N) && inRange(j+moveC[t], 1, M)
                                && terra[i+moveL[t]][j+moveC[t]]){
                            matcher.insert(cod(i, j), cod(i+moveL[t], j+moveC[t]));
                        }
                    }
                }
            }
        }

        printf("%d\n", matcher.matchings());
    }
    return 0;
}
