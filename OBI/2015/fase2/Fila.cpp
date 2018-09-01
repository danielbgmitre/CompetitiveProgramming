/*
Implementation: SQRT decomposition with Doubly Linked-Lists

Teste  1: .....     (20 pontos)
Teste  2: .....     (20 pontos)
Teste  3: ......     (20 pontos)
Teste  4: ......     (20 pontos)
Teste  5: TTT.TT..     (0 pontos)
Submission result: 80%
*/

#include <bits/stdc++.h>

using namespace std;

//onst int MAXN = 6e10 + 100;// * 1.546;
const int SQRT = 700;

struct node {
    int altura;
    node* next;
    node* prev;
    node(int h) : altura(h), next(NULL), prev(NULL) {}
    void insert(int h) {
        node* novo = new node(h);
        novo->next = this->next;
        novo->prev = this;
        if (this->next != NULL) {
            this->next->prev = novo;
        }
        this->next = novo;
    }
};

struct block {
    int maior, size;
    block* next;
    block* prev;
    node* root;
    node* end;
    block() : maior(0), size(0),
              next(NULL), prev(NULL),
              root(NULL), end(NULL) {}

    void updateMaior() {
        maior = 0;
        node* it = root;
        while (it != NULL) {
            if (it->altura > maior) {
                maior = it->altura;
            }
            it = it->next;
        }
    }

    void show() {
        cout << "comeca em " << root->altura <<" e termina em "<<end->altura<<endl;
    }

    void split() {
        node* it = root;
        for (int i=0; i<SQRT-1; i++) {
            it = it->next;
        }

        block* novo = new block();
        novo->prev = this;
        novo->size = SQRT;
        this->size = SQRT;

        novo->end = this->end;
        this->end = it;

        novo->root = it->next;

        it->next->prev = NULL;
        it->next = NULL;

        if (this->next != NULL) {
            this->next->prev = novo;
        }

        novo->next = this->next;
        this->next = novo;

        this->updateMaior();
        //this->show();
        novo->updateMaior();
        //novo->show();
    }

};

block* blocks = new block();

void add(int idx, int h){
    block* it_block = blocks;
    while (idx > it_block->size) {
        idx -= it_block->size;
        it_block = it_block->next;
    }

    node* novo = new node(h);


    if (idx == it_block->size){
        it_block->end = novo;
    }

    it_block->size++;
    if (it_block->maior < h) {
        it_block->maior = h;
    }
    if (idx == 0) {
        if (it_block->root != NULL) {
            it_block->root->prev = novo;
        }
        novo->next = it_block->root;
        if (it_block->root != NULL){
            it_block->root->prev = novo;
        }
        it_block->root = novo;
    } else {
        node* it_node = it_block->root;
        while (idx-1) {
            it_node = it_node->next;
            idx--;
        }
        novo->next = it_node->next;
        novo->prev = it_node;
        if (it_node->next != NULL) {
            it_node->next->prev = novo;
        }
        it_node->next = novo;
    }

    if (it_block->size == 2*SQRT) {
        it_block->split();
    }
}


int find(int idx, int d) {
    int _idx = idx-1;
    block* it_block = blocks;
    while (idx > it_block->size) {
        idx -= it_block->size;
        it_block = it_block->next;
    }

    node* it_node = it_block->root;
    for (int i=0; i<idx-1; i++) {
        it_node = it_node->next;
    }

    int lowerbound = it_node->altura + d;
    it_node = it_node->prev;

    while (it_block != NULL) {
        while (it_node != NULL) {
            if (it_node->altura > lowerbound) {
                return _idx;
            }
            it_node = it_node->prev;
            _idx--;
        }

        it_block = it_block->prev;

        while (it_block != NULL && it_block->maior <= lowerbound) {
            _idx -= it_block->size;
            it_block = it_block->prev;
        }

        if (it_block != NULL) {
            it_node = it_block->end;
        }
    }
    return _idx;
}

void showSequence(){
    block* first = blocks;

    while (first != NULL) {
        node* it = first->root;
        while (it != NULL) {
            printf("%d ", it->altura);
            it = it->next;
        }
        first = first->next;
    }
    printf("\n");
}

block* last_block = blocks;

void showInverted(){
    block* last = last_block;
    while (last != NULL) {
        node* it = last->end;
        while (it != NULL) {
            printf("%d ", it->altura);
            it = it->prev;
        }
        last = last->prev;
    }
    printf("\n");
}
node* last_node = NULL;

void append(int h){
    node* novo = new node(h);

    if (last_node == NULL){
        last_block->root = novo;
    } else {
        last_node->next = novo;
        novo->prev = last_node;
    }
    if (h > last_block->maior) {
        last_block->maior = h;
    }
    last_block->end = novo;
    last_block->size++;
    last_node = novo;

    if (last_block->size == 2*SQRT-1) {
        block* novo_bloco = new block();
        last_block->next = novo_bloco;
        novo_bloco->prev = last_block;

        last_block = last_block->next;
        last_node = NULL;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int N;
    scanf(" %d", &N);
    //SQRT = sqrt(N);

    int a;
    node* last_node = NULL;
    block* last_block = blocks;
    for (int i=0; i < N; i++) {
        scanf(" %d", &a);
        //add(i, a);
        append(a);
    }

    //showSequence();
    //showInverted();

    int Q;
    scanf(" %d", &Q);

    int type, arg1, arg2;
    for (int q=0; q<Q; q++) {
        scanf(" %d %d %d", &type, &arg1, &arg2);

        if (type == 0) {
            add(arg1, arg2);
        } else {
            printf("%d\n", find(arg1, arg2));
        }
    }

    //showSequence();
    //showInverted();

    return 0;
}
