//http://codeforces.com/problemset/problem/78/E
//Evacuation

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300;

const int ROOM = -1;
const int REAC = -2;
const int BAD_REAC = -3;
const int CAPS = ROOM;

class Aresta {
public:
    int from, to, rev, flow, cap;
    Aresta(){}
    Aresta(int _from, int _to, int _rev, int _flow, int _cap){
        from = _from; to = _to; rev = _rev; flow = _flow; cap = _cap;
    }
    int residuo() {return cap-flow;}
};

class EdmondsKarp {
public:
    int size;
    vector<Aresta*> *grafo;
    Aresta **prev;
    bool *vis;

    EdmondsKarp(int tam){
        size = tam;
        grafo = new vector<Aresta*>[size];
        prev = new Aresta*[size];
        vis = new bool[size];
    }

    void limpa(){
        for (int i=0; i<size; i++){
            for (size_t j=0; j<grafo[i].size(); j++){
                delete grafo[i][j];
            }
            grafo[i].clear();
        }
    }

    void destroy(){
        limpa();
        delete prev;
        delete vis;
        delete this;
    }

    void add(int s, int t, int cap){
        Aresta *a = new Aresta(s, t, grafo[t].size(), 0, cap);
        Aresta *b = new Aresta(t, s, grafo[s].size(), 0, 0);
        grafo[s].push_back(a);
        grafo[t].push_back(b);
    }

    void undirectedAdd(int s, int t, int cap){
        Aresta *a = new Aresta(s, t, grafo[t].size(), 0, cap);
        Aresta *b = new Aresta(t, s, grafo[s].size(), 0, cap);
        grafo[s].push_back(a);
        grafo[t].push_back(b);
    }

    bool bfs(int source, int sink){
        for (int i=0; i<size; i++){
            prev[i] = NULL;
            vis[i] = false;
        }

        queue<int> fila;
        fila.push(source);
        vis[source] = 1;

        int atual;
        while (!fila.empty()){
            atual = fila.front(); fila.pop();

            if (atual == sink) return true;

            for (Aresta *a : grafo[atual]){
                if (!vis[a->to] && a->residuo() > 0){
                    prev[a->to] = a;
                    vis[a->to] = true;
                    fila.push(a->to);
                }
            }
        }

        return false;
    }

    int dfs(int source, int sink){
        int flow = INT_MAX;
        int v = sink;
        while (v != source){
            flow = min(flow, prev[v]->residuo());
            v = prev[v]->from;
        }

        v = sink;
        Aresta *a;
        while (v != source){
            a = prev[v];
            a->flow += flow;
            grafo[a->to][a->rev]->flow -= flow;
            v = a->from;
        }
        return flow;
    }

    long long int flow(int source, int sink){
        int flow = 0;
        while (bfs(source, sink)){
            flow += dfs(source, sink);
        }
        return flow;
    }
};

int station[MAXN][MAXN], checkpoint[MAXN][MAXN], veneno[61][MAXN][MAXN];

struct coord{
    int x, y, qtd;
    coord(int a, int b, int c){
        x = a; y = b; qtd = c;
    }
    bool is_valid(int N){
        return (x >= 0 && x < N && y >= 0 && y < N && station[x][y] == ROOM);
    }
};

bool is_valid(int x, int y, int N){
    return coord(x, y, 0).is_valid(N);
}

inline bool operator == (const coord &a, const coord &b){
    return (a.x == b.x && a.y == b.y);
}

vector<coord> pessoas, capsulas;
int moveX[] = {-1, 0, 1, 0};  //^<v>
int moveY[] = {0, -1, 0, 1};  //^<v>

int trad(char ch){
    switch (ch) {
        case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            return ROOM;
        case 'Y':
            return REAC;
        case 'Z':
            return BAD_REAC;
    }
    return -1;
}

int how_much(char ch){
    return ch-'0';
}


int bfs(coord from, coord to, int N){
    bitset<MAXN> vis[MAXN];
    queue<pair<int, coord>> fila;
    fila.push({0, from});
    vis[from.x][from.y] = 1;

    while (!fila.empty()){
        int tempo = fila.front().first;
        coord atual = fila.front().second;
        fila.pop();

        if (atual == to) return tempo;

        if (veneno[tempo][atual.x][atual.y]){
            continue;
        }

        for (int i=0; i<4; i++){
            coord next(atual.x + moveX[i], atual.y + moveY[i], 0);
            if (next.is_valid(N) && !vis[next.x][next.y]){
                if (!veneno[tempo][next.x][next.y]){
                    fila.push({tempo + 1, next});
                    vis[next.x][next.y] = 1;
                }
            }
        }
    }

    return 999;
}

void espalha_veneno(int x, int y, int T, int N){
    veneno[0][x][y] = 1;
    for (int i=1; i<=T; i++){
        for (int lin=0; lin<N; lin++){
            for (int col=0; col<N; col++){
                if (veneno[i-1][lin][col]){
                    veneno[i][lin][col] = 1;
                    for (int move=0; move<4; move++){
                        if (is_valid(lin+moveX[move], col+moveY[move], N)){
                            veneno[i][lin+moveX[move]][col+moveY[move]] = 1;
                        }
                    }
                }
            }
        }
    }

}

int main(){
    int N, T;
    scanf(" %d %d", &N, &T);

    char ch;
    coord bad = {0, 0, 0};
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf(" %c", &ch);
            if (trad(ch) == ROOM && how_much(ch)){
                pessoas.push_back(coord(i, j, how_much(ch)));
            }
            station[i][j] = trad(ch);
            if (station[i][j] == BAD_REAC){
                bad = coord(i, j, 0);
            }
        }
    }

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf(" %c", &ch);
            if (trad(ch) == CAPS && how_much(ch)){
                capsulas.push_back(coord(i, j, how_much(ch)));
                checkpoint[i][j] = how_much(ch);
            }
        }
    }

    EdmondsKarp *din = new EdmondsKarp(MAXN);
    int sink = MAXN-1;

    for (size_t i=0; i<pessoas.size(); i++){
        din->add(0, i*2+1, pessoas[i].qtd);
    }

    for (size_t i=0; i<capsulas.size(); i++){
        din->add(i*2+2, sink, capsulas[i].qtd);
    }

    espalha_veneno(bad.x, bad.y, T, N);

    for (size_t i=0; i<pessoas.size(); i++){
        for (size_t j=0; j<capsulas.size(); j++){
            int tempo = bfs(pessoas[i], capsulas[j], N);
            if (tempo <= T){
                din->add(i*2+1, j*2+2, 999);
            }
        }
    }

    printf("%lld\n", din->flow(0, sink));
    delete din;
    return 0;
}
