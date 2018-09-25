#include <bits/stdc++.h>
#define MAX 200007
using namespace std;

int k[MAX], freq[MAX], minimo;
string A, B;
void kmp(string s){
    int x = 0,y = 0;
    int n = s.size();
    for(int i = 1; i < n; i++){
        k[i] = max(0, min(k[i-x], y-i+1));
        while(i+k[i] < n && s[k[i]] == s[i+k[i]]){
            x= i; y = i+k[i]; k[i]++;
        }
    }
}

string prefix(int idx){
    string ans = "";
    for(int i = 0; i < idx; i++) ans += B[i];

    return ans;
}
string solve(int n, int l){
    for(int i = n; i >= l; i--){
        freq[k[i]] += 1;
    }

    for(int i = l; i >= 1; i--){
        freq[i] += freq[i+1];
    }

    //for(int i = 0; i <= n; i++) cout << k[i] << " \n"[i == n];
    //for(int i = 1; i <= l; i++) cout << freq[i] << " \n"[i == l];
    for(int i = l; i >= 1; i--){
        if(freq[i] >= minimo) return prefix(i);
    }

    return "IMPOSSIBLE";
}

char temp[200005];
int main(){
    getline(cin, A);
    getline(cin, B);
    cin >> minimo;
    string C = B + "$" + A;
    kmp(C);
    cout << solve(C.size(), B.size()+1) << endl;
    return 0;
}
