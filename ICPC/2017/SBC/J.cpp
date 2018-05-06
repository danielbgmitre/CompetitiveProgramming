//https://www.urionlinejudge.com.br/judge/pt/problems/view/2667
//Jogo de Boca

#include <bits/stdc++.h>

using namespace std;

int main(){
    string palavra;
    cin >> palavra;

    int buffer = 0;
    for (char l : palavra){
        buffer = (buffer + (l - '0'))%3;
    }
    cout << buffer <<endl;

    return 0;
}
