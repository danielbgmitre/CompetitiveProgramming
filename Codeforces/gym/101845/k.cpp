#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 600000;
double arr[MAXN];
int main(){
    int n;
    scanf("%d", &n);
    double res = 0;

    double tempo, prob;
    for (int i=0; i<n; i++){
        scanf("%lf %lf", &tempo, &prob);
        arr[i] = tempo * prob;
    }

    sort(arr, arr+n);

    for (int i=0; i<n; i++){
        if (i){
            arr[i] += arr[i-1];
        }

        res += arr[i];
    }

    printf("%.9lf\n", res/(double)n);

    return 0;
}
