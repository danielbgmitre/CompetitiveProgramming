//http://acm.timus.ru/problem.aspx?num=1846
//GDC 2010 - utilizando nos dinamicos
#include <bits/stdc++.h>

const int MAXQ = 1e5 + 10;
const int MAXN = 1e9 + 10;

using namespace std;

#define cnt first
#define pos second

int gcd(int a, int b){
    return (b==0)? a : gcd(b, a%b);
}

struct node {
    int info;
    node *left, *right;

    node (int value = 0) {
        info = value;
    }

    void build(int low, int high){
        if (low < high){
            int mid = (low+high)>>1;

            left = new node();
            left->build(low, mid);

            right = new node();
            right->build(mid+1, high);
        }
    }

    void add(int value, int low, int high, int pos){
        if (low == high && low == pos) {
            info = value;
        } else if (low <= pos && pos <= high) {
            int mid = (low+high)>>1;

            left->add(value, low, mid, pos);
            right->add(value, mid+1, high, pos);

            info = gcd(left->info, right->info);
        }
    }

    void remove(int low, int high, int pos){
        add(0, low, high, pos);
    }

} root;

map<int, pair<int, int>> contador;

int main(){
    int N;
    scanf(" %d", &N);

    root.build(0, N);

    char op;
    int num, qtd;
    pair<int, int> temp;
    for (int i=0; i<N; i++){
        scanf(" %c %d", &op, &num);

        switch (op) {
            case '-':
                qtd = --contador[num].cnt;
                if (qtd == 0){
                    root.remove(0, N, contador[num].pos);
                }
                break;

            case '+':
                qtd = ++contador[num].cnt;
                if (qtd == 1){
                    contador[num].pos = i;
                    root.add(num, 0, N, i);
                }
                break;
        }
        printf("%d\n", max(1, root.info));
    }

    return 0;
}
