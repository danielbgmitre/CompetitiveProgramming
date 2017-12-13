//http://codeforces.com/contest/903/problem/D
//Almost Difference

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int numbers[MAXN];
int counter = 0;

struct node {
    int value, menor, maior;
    node *l, *r;

    node(){
        value = 0;
        menor = INT_MAX;
        maior = INT_MIN;
    }

    void limpa(){
        value = 1;
        menor = INT_MAX;
        if (l != NULL){
            l->limpa();
        }
        if (r != NULL){
            r->limpa();
        }
    }

    void build(int left, int right){
        if (left == right){
            value = menor = maior = numbers[left];
        } else {
            int mid = (left + right)>>1;
            l = new node();
            r = new node();

            l->build(left, mid);
            r->build(mid+1, right);

            value = l->value + r->value;
            menor = min(l->menor, r->menor);
            maior = max(l->maior, r->maior);
        }
    }

    long long int queryLower(int left, int right, int qL, int qR, int lower){
        if (left >= qL && right <= qR && menor > lower){
            counter+=(right-left)+1;
            return value;
        } else if (left > qR || right < qL){
            return 0;
        } else if (left == right && menor <= lower){
            return 0;
        }

        int mid = (left+right)>>1;
        return l->queryLower(left, mid, qL, qR, lower) + r->queryLower(mid+1, right, qL, qR, lower);
    }

    long long int queryUpper(int left, int right, int qL, int qR, int upper){
        if (left >= qL && right <= qR && maior < upper){
            counter+= (right-left)+1;
            return value;
        } else if (left > qR || right < qL){
            return 0;
        } else if (left == right && maior >= upper){
            return 0;
        }

        int mid = (left+right)>>1;
        return l->queryUpper(left, mid, qL, qR, upper) + r->queryUpper(mid+1, right, qL, qR, upper);
    }
} root;

int main(){
    int N;
    scanf(" %d", &N);

    for (int i=1; i<=N; i++){
        scanf(" %d", &numbers[i]);
    }
    root.build(1, N);

    long long int res = 0;
    for (int i=1; i<=N; i++){
        counter = 0;
        res += root.queryLower(1, N, i+1, N, numbers[i]+1);
        res -= numbers[i]*counter;

        counter = 0;
        res += root.queryUpper(1, N, i+1, N, numbers[i]-1);
        res -= numbers[i]*counter;
    }
    printf("%lld\n", res);

    return 0;
}
