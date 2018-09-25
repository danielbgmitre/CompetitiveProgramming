#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node{
    struct node *word[10];
    bool end;
} *root;

void init(){
    root = new node();
    root->end = false;
}

void add(string s){
    node* current = root;

    for(int i = 0; i < s.size(); i++){
        int number = s[i]-'0';

        if(current->word[number] == NULL) current->word[number] = new node();

        current = current->word[number];
    }

    current->end = true;
}

ll pick(string s, int type){
    node* current = root;

    ll valor = 0;
    for(int i = 0; i < s.size(); i++){
        int number = s[i]-'0';

        int best = 0, n_best = type? 0:10;
        for(int j = 0; j < 10; j++){
            if(current->word[j] != NULL){
                int calc = (j+number)%10;
                if(calc >= n_best && type){
                    best = j;
                    n_best = calc;
                }

                if(calc <= n_best && !type){
                    best = j;
                    n_best = calc;
                }
            }
        }

        if(current->word[best] == NULL) return type? 0:1e18+7;
        current = current->word[best];
        valor = 10*valor + n_best;
    }

    return valor;
}

string enche(string &s){
    int tam = s.size();
    string ans = "";
    for(int i = 0; i < 19-tam; i++) ans += "0";
    return ans+s;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    init();
    string A, aux;
    long long maior = 0, menor = 1e18 + 7;
    for(int i = 0; i < n; i++){
        cin >> A;
        aux = enche(A);
        maior = max(maior, pick(aux, true));
        menor = min(menor, pick(aux, false));
        add(aux);
    }

    cout << menor << " " << maior << endl;
    return 0;
}
