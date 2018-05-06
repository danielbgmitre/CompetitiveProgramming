#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 123;

map<unsigned int, vector<int> > positions;

int solve(unsigned int actual, int pos, int tam) {
    if (!positions.count(actual+1)) return tam;

    vector<int> &next = positions[actual+1];
    vector<int>::iterator next_pos = lower_bound(next.begin(), next.end(), pos);
    if (next_pos != next.end()){
        return solve(actual+1, *next_pos, tam+1);
    }
    return tam;
}

void show(int actual, int pos, int tam){
    vector<int> &next = positions[actual+1];
    vector<int>::iterator next_pos = lower_bound(next.begin(), next.end(), pos);
    printf("%d", pos+1);
    if (tam > 1){
        printf(" ");
        show(actual+1, *next_pos, tam-1);
    } else {
        printf("\n");
    }
}

int main() {
    int N;
    scanf(" %d", &N);

    unsigned int temp;
    for (int i=0; i<N; i++){
        scanf("%d", &temp);
        positions[temp].push_back(i);
    }

    int start=0, tam=0;
    for (auto p : positions) {
        int temp = solve(p.first, p.second[0], 1);
        if (temp > tam) {
            tam = temp;
            start = p.first;
        }
    }
    printf("%d\n", tam);
    show(start, positions[start][0], tam);
    return 0;
}
