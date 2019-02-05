/*
 * Database of Clients
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2906
 * O(n) solution
 */

#include <bits/stdc++.h>

using namespace std;

set<string> clients;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string word;
    for (int i=0; i<N; i++) {
        cin >> word;
        bool ignore = false;
        bool provider = false;

        stringstream ss;
        for (char ch : word) {
            if (ch == '@') {
                provider = true;
            }
            if (ch == '+') {
                ignore = true;
            }
            if (provider || (!ignore && ch != '.')) {
                ss << ch;
            }
        }
        clients.insert( ss.str() );
    }

    cout << clients.size() << endl;

    return 0;
}
