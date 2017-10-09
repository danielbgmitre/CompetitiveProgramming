//https://www.urionlinejudge.com.br/judge/pt/problems/view/1264
//Um problema fácil!

#include <bits/stdc++.h>

using namespace std;

string ordem = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
map<char, int> conv;

void iniciaMapa(){
    int pos = 0;
    for (char c : ordem){
        conv[c] = pos++;
    }
    conv['-'] = 0;
}

int main(){
    string s;
    iniciaMapa();

    while (getline(cin, s)){
        char maior = '0';
        for (char c : s){
            if (c > maior){
                maior = c;
            }
        }

        int res = 0;
        if (conv[maior] == 0){
            res = 2;
        }

        for (int i=conv[maior]; i<=conv['z'] && !res; i++){
            int soma = 0;

            int pos = 1;
            for (char c : s){
                soma = (soma + conv[c])%i;
            }

            if (soma == 0){
                res = i+1;
            }
        }
        if (res){
            printf("%d\n", res);
        } else {
            printf("such number is impossible!\n");
        }
    }

    return 0;
}
