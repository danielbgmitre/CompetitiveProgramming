#include <bits/stdc++.h>
#define MAX 10007
using namespace std;

bool solve(long long a, long long b, long long c){
    return (a < b + c) && (b < a + c) && (c < a + b);
}

int main(){
    int n;

    scanf("%d", &n);
    long long a, b, c;
    bool res = true;
    while (n--){
        scanf("%lld %lld %lld", &a, &b, &c);
        res = res && solve(a, b, c);
    }

    printf("%s\n", res ? "YES" : "NO");

    return 0;
}
