#include "bits/stdc++.h"
#define MAXN 102002
using namespace std;

int acm[MAXN], arr[MAXN];
int n;

void solve(){
    scanf("%d", &n);

    bool gamb = true;
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        if (arr[i] != 2 && arr[i] != 0) gamb = false;
    }

    if (gamb){
        printf("Y\n");
        return;
    }

    sort(arr, arr+n, greater <int> ());

    for (int i=0; i<n; i++){
        if (i > 0) acm[i] += acm[i-1];

        if (acm[i] < arr[i]){
            if (i + 1 >= n){
                printf("N\n");
                return;
            }

            acm[i+1]++;

            if (i + arr[i]-acm[i] + 1 > n){
                printf("N\n");
                return;
            }

            acm [i + arr[i]-acm[i] + 1 ]--;


        } else if (acm[i] > arr[i]){
            if (i + 1 >= n){
                printf("N\n");
                return;
            }

            acm[i+1] += acm[i] - arr[i];
            acm[i+2] -= acm[i] - arr[i];
        }
        //
        // for (int j=0; j<6; j++){
        //     printf("%d%c", acm[j], " \n"[j == 5]);
        // }
    }

    printf("Y\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        memset(acm, 0, sizeof acm);
        solve();
    }

    return 0;
}
