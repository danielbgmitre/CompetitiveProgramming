#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string condicao;
    while (cin >> condicao) {
        if (condicao == "esquerda") {
            cout << "ingles" << endl;
        } else if (condicao == "direita") {
            cout << "frances" << endl;
        } else if (condicao == "nenhuma") {
            cout << "portugues" <<endl;
        } else {
            cin >> condicao;
            cout << "caiu" << endl;
        }
    }
    return 0;
}
