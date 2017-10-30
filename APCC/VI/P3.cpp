//http://acm.timus.ru/problem.aspx?space=1&num=2068
//Game of Nuts

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    scanf(" %d", &N);

    int winner = 0, temp;
    for (int i=0; i<N; i++){
        scanf(" %d", &temp);
        winner += (temp-1)>>1;
    }
    if (winner & 1){
        printf("Daenerys\n");
    } else {
        printf("Stannis\n");
    }

    return 0;
}
