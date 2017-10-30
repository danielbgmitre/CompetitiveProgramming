//http://acm.timus.ru/problem.aspx?space=1&num=1100
//Final Standings

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 150000;

vector<int> counting[110];

int main(){
    int N;
    scanf(" %d", &N);

    int temp1, temp2;
    for (int i=0; i<N; i++){
        scanf(" %d %d", &temp1, &temp2);
        counting[temp2].push_back(temp1);
    }

    for (int i=110; i>=0; i--){
        for (int id : counting[i]){
            printf("%d %d\n", id, i);
        }
    }
    return 0;
}
