#include <bits/stdc++.h>

using namespace std;

int required[500];
vector<int> sessoes;

int current_required(){
    int total = 0;
    for (int i : sessoes) {
        total += required[i];
    }
    return total;
}

void cortaMaior(){
    int maior = 0;
    for (int i=0; i<sessoes.size(); i++) {
        if (sessoes[i] > sessoes[maior]) {
            maior = i;
        }
    }
    int tam = sessoes[maior];
    int half = tam/2;
    sessoes[maior] = half;
    sessoes.push_back(tam-1-half);
}

void start(){
    int a = 0;
    for (int i=0; i<500; i++) {
        a += i;
        required[i] = a;
    }
}

void showSessoes(){
    cout << "sessoes de treinamento: ";
    for (int i : sessoes) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int N, P;
    scanf(" %d %d", &N, &P);

    start();
    int last = 0;
    sessoes.push_back(0);

    char temp;
    for (int i=0; i<N; i++) {
        scanf(" %c", &temp);
        temp -= '0';
        if (temp == 0 && sessoes[last] > 0) {
            sessoes.push_back(0);
            last++;
        }
        if (temp == 1) {
            sessoes[last]++;
        }
    }

    int res = 0;
    while (current_required() > P) {
        cortaMaior();
        res++;
    }
    cout << res << endl;

    return 0;
}
