#include <bits/stdc++.h>

using namespace std;

int main(){
    int NC;
    scanf(" %d", &NC);

    for (int nc=1; nc<=NC; nc++){
        int n, m;
        scanf(" %d %d", &n, &m);

        vector<int> soldados;
        for (int i=1; i<=n; i++){
            soldados.push_back(i);
        }

        int i = 0;
        while (soldados.size() > 1){
            i += m-1;
            i %= soldados.size();
            soldados.erase(soldados.begin()+i);
        }

        printf("Case %d: %d\n", nc, soldados[0]);
    }

    return 0;
}
