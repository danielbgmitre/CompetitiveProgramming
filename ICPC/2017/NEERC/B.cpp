#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 15;

vector<int> sequences[MAXN];
int tam = 0;

int busca_binaria(int value, int from, int to){
    if (from > to) return -1;
    if (from == to) {
        if (sequences[from].back() < value) {
            return from;
        } else {
            return -1;
        }
    }

    int mid = (from+to)/2;
    if (sequences[mid].back() < value){
        return busca_binaria(value, from, mid);
    } else {
        return busca_binaria(value, mid+1, to);
    }
}

int main(){
    int N;
    scanf(" %d", &N);

    int temp;
    for (int i=0; i<N; i++) {
        scanf(" %d", &temp);

        int pos = busca_binaria(temp, 0, tam-1);
        if (pos == -1){
            sequences[tam++].push_back(temp);
        } else {
            sequences[pos].push_back(temp);
        }
    }

    for (int i=0; i<tam; i++){
        for (int j=0; j<sequences[i].size(); j++){
            printf("%d", sequences[i][j]);
            printf(j+1<sequences[i].size()? " " : "\n");
        }
    }

    return 0;
}
