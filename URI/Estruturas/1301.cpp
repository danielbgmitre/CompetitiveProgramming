//https://www.urionlinejudge.com.br/judge/pt/problems/view/1301
//Produto do Intervalo

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int seq[MAXN];  //1-indexed

inline char symbol_of(int a){
    if (a > 0){
        return '+';
    } else if (a < 0){
        return '-';
    }
    return '0';
}

inline int minimize(int a){
    if (a > 0){
        return 1;
    } else if (a < 0){
        return -1;
    }
    return 0;
}

struct node {
    int value;
    node *l, *r;

    node(){
        value = 1;
    }

    void limpa(){
        value = 1;
        if (l != NULL){
            l->limpa();
        }
        if (r != NULL){
            r->limpa();
        }
    }

    void build(int left, int right){
        if (left == right){
            value = seq[left];
        } else {
            int mid = (left + right)>>1;
            l = new node();
            r = new node();

            l->build(left, mid);
            r->build(mid+1, right);

            value = l->value * r->value;
        }
    }

    int query(int left, int right, int qL, int qR){
        if (left >= qL && right <= qR){
            return value;
        } else if (left > qR || right < qL){
            return 1;
        }

        int mid = (left+right)>>1;
        return l->query(left, mid, qL, qR) * r->query(mid+1, right, qL, qR);
    }

    void update(int left, int right, int qL, int qR, int value){
        if (left > qR || right < qL) return;

        if (left == right){
            if (left == qL) this->value = minimize(value);
        } else {
            int mid = (left+right)>>1;
            l->update(left, mid, qL, qR, value);
            r->update(mid+1, right, qL, qR, value);
            this->value = l->value * r->value;
        }
    }
} root;


int main(){
    int N, K;
    while (scanf(" %d %d", &N, &K) != EOF){
        for (int i=1; i<=N; i++){
            scanf(" %d", &seq[i]);
            seq[i] = minimize(seq[i]);
        }

        //root.limpa();
        root.build(1, N);

        char op;
        int arg1, arg2;
        for (int i=0; i<K; i++){
            scanf(" %c %d %d", &op, &arg1, &arg2);
            switch (op) {
                case 'P':
                    printf("%c", symbol_of(root.query(1, N, arg1, arg2)));
                    break;
                case 'C':
                    root.update(1, N, arg1, arg1, arg2);
                    break;
            }
        }
        printf("\n");
    }

    return 0;
}
