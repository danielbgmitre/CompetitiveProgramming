#include <bits/stdc++.h>

using namespace std;

struct node{
    struct node* word[2];
    bool end;
} *root;

void init(){
    root = new node();
    root->end = false;
}
void add(string &s, int ini, int fim){
    node* current = root;
    for(int i = ini; i < fim; i++){
        int letter = s[i]-'0';
        // cout << s[i] << " \n"[i == fim-1];

        if(current->word[letter] == NULL) current->word[letter] = new node();

        current = current->word[letter];
        current->end = true;
    }
}

int solve(string &s){
    node* current = root;
    bool flag = false;
    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        int letter = s[i]-'0';
        int inversa = letter ^ 1;
        if (flag) {
            swap(letter, inversa);
            flag = false;
        }
        if (current->word[letter] != NULL){
            current = current->word[letter];
            continue;
        }

        if (current->word[inversa] == NULL){
            return -1;
        }

        if (current->word[inversa]->word[letter] != NULL){
            current = current->word[inversa];
            flag = true;
            ans++;
            continue;
        }
        cout << i << endl;
        return -1;
    }

    return ans;
}
int main(){
    string A,B;
    cin >> A;
    cin >> B;
    string C = A + A;
    init();
    for(int i = 0; i < A.size(); i++){
        add(C ,i, i+A.size());
    }

    cout << solve(B) << endl;
    return 0;
}
