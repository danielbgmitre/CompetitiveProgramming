// https://www.urionlinejudge.com.br/judge/pt/problems/view/1582
// O teorema de pitágoras

#include <bits/stdc++.h>

using namespace std;

int gdc(int a, int b){
    if (b == 0) return a;
    return gdc(b, a%b);
}

int gdc(int a, int b, int c){
    return gdc(gdc(a, b), c);
}

bool isPythagoreanTriple(int a, int b, int c){
    if (a*a == b*b + c*c) return true;
    if (b*b == a*a + c*c) return true;
    if (c*c == a*a + b*b) return true;
    return false;
}

int main(){
    int A, B, C;
    while (scanf(" %d %d %d", &A, &B, &C) != EOF){
        if (isPythagoreanTriple(A, B, C)){
            if (gdc(A, B, C) == 1){
                printf("tripla pitagorica primitiva\n");
            } else {
                printf("tripla pitagorica\n");
            }
        } else {
            printf("tripla\n");
        }
    }

    return 0;
}
