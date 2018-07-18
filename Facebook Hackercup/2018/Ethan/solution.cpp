#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2018;

int idx(char c) {
    return c-'A';
}

bool contains(string a, string b) {
    size_t i = 0;
    size_t j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++; j++;
        } else if (i == 0) {
            j++;
        } else {
            i = 0;
        }
    }
    return i == a.size();
}

int main() {
    int N;
    scanf(" %d", &N);

    string s;
    char temp[MAXN];

    for (int i=1; i<=N; i++) {
        char next[55];
        bitset<55> visited;
        scanf(" %2017s", temp);
        cout << "Case #"<<i<<": ";

        int tam = strlen(temp);
        int loop = -1;
        bool gotcha = false;
        for (int p=0; p+1<tam && loop == -1; p++) {
            if (!visited[idx(temp[p])]) {
                visited[idx(temp[p])] = 1;
                next[idx(temp[p])] = temp[p+1];
            } else if (next[idx(temp[p])] != temp[p+1]) {
                loop = p;
            }


            string out;
            for (int p=0; p<loop; p++) {
                out += temp[p];
            }
            out += temp;


            if (!contains(temp, out)) {
                cout << out << endl;
                gotcha = true;
            } else {
                loop = -1;
            }
        }

        if (!gotcha) {
            cout << "Impossible" << endl;
        }
    }


    return 0;
}
