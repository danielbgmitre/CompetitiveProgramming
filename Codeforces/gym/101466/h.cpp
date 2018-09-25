#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int aux;
    for (int i=1; i<=n; i++){
        if (i == 1){
            printf("*");
            aux = n-2;
            while(aux--) printf(" ");
            printf("*");
            printf(" ");
            aux = n;
            while(aux--) printf("*");
            printf("\n");
        } else if (i == n){
            aux = n;
            while(aux--) printf("*");
            printf(" ");
            aux = n-2;
            printf("*");
            while(aux--) printf(" ");
            printf("*");
            printf("\n");
        } else {
            printf("*");
            aux = n-2;
            while(aux--) printf(" ");
            printf("*");
            printf(" ");
            printf("*");
            aux = n-2;
            while(aux--) printf(" ");
            printf("*");
            printf("\n");
        }
    }

    return 0;
}
