#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

int main(){
    scanf("%lld %lld", &n, &m);

    ll num, k;
    for (int i=0; i<m; i++){
        scanf("%lld %lld", &num, &k);

        ll index = n-1;
        ll res = 0;
        index -= k%n;
        index %= n;
        index += n;
        index %= n;
        index ++;
        index %= n;
        for (int j=0; j<n; j++){
            if (((1ll << index) & num)){
                res += 1ll << j;
            }

            index++;
            index %= n;
            index += n;
            index %= n;
        }
        printf("%lld\n", res);
    }

    return 0;
}
