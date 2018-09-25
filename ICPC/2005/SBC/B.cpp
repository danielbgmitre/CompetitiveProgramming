#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, M;
    string disciplina, requisito;
    char temp[10000];
    while (scanf(" %d %d", &N, &M) && !(N == 0 && M == 0)) {
        vector<string> prioridade;
        map<string, int> qtd;
        map<string, vector<string>> graph;

        for (int i=0; i<N; i++) {
            //string disciplina;
            int K;
            scanf(" %s", temp);
            scanf(" %d", &K);
            disciplina = temp;

            vector<string>::iterator pos = find(prioridade.begin(), prioridade.end(), disciplina);
            if (pos == prioridade.end()) {
                prioridade.push_back(disciplina);
            }
            qtd[disciplina] = K;

            for (int k=0; k<K; k++) {
                scanf(" %s", temp);
                requisito = temp;
                graph[requisito].push_back(disciplina);
                if (!count(prioridade.begin(), prioridade.end(), requisito)){
                    prioridade.push_back(requisito);
                }
            }
        }

        int cursadas = 0;
        int total = prioridade.size();

        vector<vector<string>> semestres;

        while (cursadas != total) {
            semestres.push_back(vector<string>());
            for (int i=0; i<total; i++) {
                if (qtd[prioridade[i]] == 0) {
                    (*semestres.rbegin()).push_back(prioridade[i]);
                }
                if ((*semestres.rbegin()).size() == M) {
                    break;
                }
            }

            for (string &s : (*semestres.rbegin())) {
                qtd[s] = 999;
                for (string& pos_requisito : graph[s]) {
                    qtd[pos_requisito]--;
                }
            }

            cursadas += (*semestres.rbegin()).size();
        }

        printf("Formatura em %u semestres\n", semestres.size());
        for (int i=1; i<=semestres.size(); i++) {
            printf("Semestre %d :", i);
            sort(semestres[i-1].begin(), semestres[i-1].end());
            for (string &materia : semestres[i-1]) {
                printf(" %s", materia.c_str());
            }
            printf("\n");
        }
    }

    return 0;
}
