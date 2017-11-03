//http://acm.timus.ru/problem.aspx?num=1846
//GDC 2010 - utilizando nos estaticos

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

const int MAXN = 1e5 + 20;

int tree[MAXN*4];

int gcd(int a, int b){
    return (b==0)? a : gcd(b, a%b);
}

void update(int id, int lower, int high, int value, int pos){
    if (lower > pos || high < pos) return;

    if (lower == high){
        if (lower == pos) tree[id] = value;
    } else if (lower < high){
        int dobro = id<<1;
        int meio = (high+lower)>>1;

        update(dobro+1, lower, meio, value, pos);
        update(dobro+2, meio+1, high, value, pos);

        tree[id] = gcd(tree[dobro+1], tree[dobro+2]);
    }
}

map<int, pair<int, int>> contador;

int main(){
    int N, x;
    scanf(" %d", &N);

    char op;
    for (int i=0; i<N; i++){
        scanf(" %c %d", &op, &x);
        pair<int, int> &q = contador[x];

        switch (op) {
            case '+':
                q.st++;
                if (q.st == 1){
                    q.nd = i;
                    update(0, 0, N, x, i);
                }
                break;

            case '-':
                q.st--;
                if (q.st == 0){
                    update(0, 0, N, 0, q.nd);
                }
                break;
        }
        printf("%d\n", max(1, tree[0]));
    }

    return 0;
}
