#include <bits/stdc++.h>
#define MAXN 30000010
using namespace std;

const int MOD = 30000000;

int arr[MAXN];
int ans[MAXN];
int cont[MAXN];

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i=0; i<m; i++){
        scanf("%d", &arr[i]);
        cont[arr[i]]++;
    }

    for (int i=m; i<n; i++){
        arr[i] = arr[i-m] + arr[i-m+1];
        arr[i] %= MOD;
        cont[arr[i]]++;
    }

    int idx = 1;
    for (int i=0; i<=30000000; i++){
        while(cont[i]--){
            ans[idx++] = i;
        }
    }

    int num;
    for (int i=0; i<q; i++){
        scanf("%d", &num);
        printf("%d\n", ans[num]);
    }


    return 0;
}
