#include <bits/stdc++.h>
#define MAX 10007
using namespace std;


vector <char> res;

int main(){
    int n;
    scanf("%d", &n);

    while (n){
        if (n & 1){
            n -= 1;
            n /= 2;
            res.push_back('A');
        } else {
            n -= 2;
            n /= 2;
            res.push_back('B');
        }
    }

    for (int i=res.size()-1; i>=0; i--){
        printf("%c", res[i]);
    }
    printf("\n");

    return 0;
}
