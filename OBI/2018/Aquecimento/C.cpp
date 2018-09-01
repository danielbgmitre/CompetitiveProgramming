#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

string key;
string input;

bool isVogal(char c) {
    return c == 'a' || c == 'e' || c == 'i'
        || c == 'o' || c == 'u';
}

int main() {
    int N;
    cin >> key >> N;
    getline(cin, input);
    for (int teste=0; teste<N; teste++){
        fflush(stdin);
        getline(cin, input);
        int curr_i = 0;
        bool waiting_word = true;
        bool consoante = false;

        for (int i=0; i<input.size(); i++) {
            if (input[i] == ' ') {
                waiting_word = true;
                continue;
            }

            if (waiting_word) {
                consoante = !isVogal(input[i]);
                waiting_word = false;
            }

            if (consoante) {
                if (input[i] < 'a') {
                    input[i] = 'A'+((input[i]-'A' + key[curr_i]-'a')%26);
                } else {
                    input[i] = 'a'+((input[i]-'a' + key[curr_i]-'a')%26);
                }
            }

            curr_i++;
            curr_i %= key.size();
        }
        cout << input << endl;
    }

    return 0;
}
