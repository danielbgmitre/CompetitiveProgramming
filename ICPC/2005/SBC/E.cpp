//TODO failing in some test cases

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

typedef pair<long long, long long> pii;

bool falha = false;

vector<pii> disco;
vector<string> nomes;

void remove(string& nome) {
    auto it = find(nomes.begin(), nomes.end(), nome);
    if (it != nomes.end()) {
        long long pos = it - nomes.begin();
        disco.erase(disco.begin() + pos);
        nomes.erase(it);
    }
}

long long free_space[9];

void conta_livres(long long total_size) {
    memset(free_space, 0, sizeof free_space);
    long long bucket_size = total_size / 8;
    for (int i=0; i < disco.size(); ) {
        long long startb = disco[i].st / bucket_size;
        long long endb = disco[i].nd / bucket_size;
        if (startb != endb) {
            long long curr_final = (startb+1) * bucket_size;
            free_space[startb] += curr_final - disco[i].st;
            disco[i].st = curr_final;
        } else {
            free_space[startb] += disco[i].nd - disco[i].st;
            i++;
        }
    }
}

void otimiza() {
    long long ultimo = 0;
    for (int i=0; i<disco.size(); i++) {
        long long diff = disco[i].st - ultimo;
        disco[i].st -= diff, disco[i].nd -= diff;
        ultimo = disco[i].nd;
    }
}

void insere(string nome, long long size, long long total_size, bool first_try = true){
    if (disco.size() == 0) {
        if (total_size < size) {
            falha = true;
        } else {
            disco.push_back({0, size});
            nomes.push_back(nome);
        }
        return;
    }


    if (disco[0].st >= size) {
        disco.insert(disco.begin(), {0, size});
        nomes.insert(nomes.begin(), nome);
        return;
    }
    for (int i=1; i<disco.size(); i++) {
        if ((disco[i].st - disco[i-1].nd) >= size) {
            disco.insert(
                disco.begin()+i,
                {disco[i-1].nd, disco[i-1].nd + size}
            );
            nomes.insert(nomes.begin()+i, nome);
            return;
        }
    }
    if ((total_size - disco[disco.size()-1].nd) >= size) {
        disco.push_back(
            {disco[disco.size()-1].nd, disco[disco.size()-1].nd + size}
        );
        nomes.push_back(nome);
        return;
    }
    if (first_try) {
        otimiza();
        insere(nome, size, total_size, false);
    } else {
        falha = true;
    }
}

long long read_Kb() {
    long long tam = 0;
    char c;
    while (scanf(" %c", &c) && c <= '9') {
        tam *= 10;
        tam += c - '0';
    }

    if (c == 'G') {
        tam *= 1024;
        c = 'M';
    }
    if (c == 'M') {
        tam *= 1024;
    }

    scanf(" %c", &c);

    return tam;
}

int main() {
    int N;
    while (scanf(" %d", &N) && N) {
        long long total_size = read_Kb();
        falha = false;
        disco.clear();
        nomes.clear();
        char op[100], temp[100];
        string nome;
        long long size;
        for (int i=0; i<N; i++) {
            scanf(" %s", op);
            if (op[0] == 'i') {           //insere
                scanf(" %s", temp);
                nome = temp;
                size = read_Kb();
                insere(nome, size, total_size);
            } else if (op[0] == 'r') {    //remove
                scanf(" %s", temp);
                nome = temp;
                remove(nome);
            } else {                        //otimiza
                otimiza();
            }
        }

        if (falha) {
            printf("ERRO: disco cheio\n");
        } else {
            conta_livres(total_size);
            long long bkt_sz = total_size/8;
            for (int i=0; i<8; i++) {
                long long P = (100*free_space[i])/bkt_sz;
                P = 100 - P;
                if (P > 75) {
                    printf("[ ]");
                } else if (P <= 25){
                    printf("[#]");
                } else {
                    printf("[-]");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
