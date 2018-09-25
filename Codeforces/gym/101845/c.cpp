#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 126;

string source, sink;
int n;

ll m[MAXN][MAXN];

void floyd(){
    for (int k=0; k<MAXN; k++){
        for (int i=0; i<MAXN; i++){
            for (int j=0; j<MAXN; j++){
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> source >> sink;
    cin >> n;

    for (int i=0; i<MAXN; i++){
        for (int j=0; j<MAXN; j++){
            m[i][j] = 1e17;
        }
    }

    char de, para;
    int custo;
    for (int i=0; i<n; i++){
        cin >> de >> para >> custo;
        m[de-33][para-33] = min(m[de-33][para-33], (ll)custo);
    }

    floyd();
    ll res = 0;

    for (int i=0; i<source.size(); i++){
        int from = source[i]-33;
        int to = sink[i]-33;
        if (from != to){
            if (m[from][to] == 1e17){
                cout << -1 << endl;
                return 0;
            } else {
                res += m[from][to];
            }
        }
    }

    cout << res << endl;

    return 0;
}
