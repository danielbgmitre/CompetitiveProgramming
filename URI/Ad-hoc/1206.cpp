#include <bits/stdc++.h>

using namespace std;

char tabuleiro[8][8];

void showTabuleiro(){
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++){
            printf("%c%c", tabuleiro[i][j], (j==7)? '\n' : ' ');
        }
    }
}

void limpa() {
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++) {
            tabuleiro[i][j] = '_';
        }
    }
}

bool isInRange(int x) {
    return x >= 0 && x <= 7;
}

bool isValid(int i, int j){
    return isInRange(i) && isInRange(j);
}

bool isPeca(int i, int j) {
    return tabuleiro[i][j] != '_' && tabuleiro[i][j] != '&';
}

bool findPecaLoop(int i, int j, char peca, void (*move)(int&, int&)) {
    move(i, j);

    while (isValid(i, j)) {
        if (isPeca(i, j)) {
            return tabuleiro[i][j] == peca;
        }
        move(i, j);
    }
    return false;
}

bool findPeca(int i, int j, char peca, void (*move)(int&, int&)) {
    move(i, j);

    if (isValid(i, j)) {
        return tabuleiro[i][j] == peca;
    }
    return false;
}

void Up(int &i, int &j) {
    i--;
}
void Down(int &i, int &j) {
    i++;
}
void Left(int &i, int &j) {
    j--;
}
void Right(int &i, int &j) {
    j++;
}
void LeftUp(int &i, int &j) {
    Left(i, j); Up(i, j);
}
void LeftDown(int &i, int &j){
    Left(i, j); Down(i, j);
}
void RightUp(int &i, int &j){
    Right(i, j); Up(i, j);
}
void RightDown(int &i, int &j){
    Right(i, j); Down(i, j);
}

bool findPeao(int i, int j){
    bool found = false;
    found = found || findPeca(i, j, 'P', &RightDown);
    found = found || findPeca(i, j, 'P', &LeftDown);
    return found;
}

bool findTorre(int i, int j){
    bool found = false;
    found = found || findPecaLoop(i, j, 'T', &Right);
    found = found || findPecaLoop(i, j, 'T', &Left);
    found = found || findPecaLoop(i, j, 'T', &Up);
    found = found || findPecaLoop(i, j, 'T', &Down);
    return found;
}

bool findBispo(int i, int j){
    bool found = false;
    found = found || findPecaLoop(i, j, 'B', &RightUp);
    found = found || findPecaLoop(i, j, 'B', &LeftUp);
    found = found || findPecaLoop(i, j, 'B', &RightDown);
    found = found || findPecaLoop(i, j, 'B', &LeftDown);
    return found;
}

bool findRainha(int i, int j){
    bool found = false;
    found = found || findPecaLoop(i, j, 'R', &Right);
    found = found || findPecaLoop(i, j, 'R', &Left);
    found = found || findPecaLoop(i, j, 'R', &Up);
    found = found || findPecaLoop(i, j, 'R', &Down);

    found = found || findPecaLoop(i, j, 'R', &RightUp);
    found = found || findPecaLoop(i, j, 'R', &LeftUp);
    found = found || findPecaLoop(i, j, 'R', &RightDown);
    found = found || findPecaLoop(i, j, 'R', &LeftDown);
    return found;
}

bool findRei(int i, int j){
    bool found = false;
    found = found || findPeca(i, j, 'W', &Right);
    found = found || findPeca(i, j, 'W', &Left);
    found = found || findPeca(i, j, 'W', &Up);
    found = found || findPeca(i, j, 'W', &Down);

    found = found || findPeca(i, j, 'W', &RightUp);
    found = found || findPeca(i, j, 'W', &LeftUp);
    found = found || findPeca(i, j, 'W', &RightDown);
    found = found || findPeca(i, j, 'W', &LeftDown);
    return found;
}

bool isReiCheck(int i, int j) {
    bool check = !isValid(i, j);
    check = check || findPeao(i, j);
    check = check || findTorre(i, j);
    check = check || findBispo(i, j);
    check = check || findRainha(i, j);
    check = check || findRei(i, j);
    return check;
}

void (* king_movements [])(int&, int&)  = {&Right, &Left, &Up, &Down, &RightUp, &LeftUp, &RightDown, &LeftDown};

void moveMyKing(int &i, int &j, int movement) {
    if (movement < 8) {
        king_movements[movement](i, j);
    }
}

int main() {
    int N;
    while (~scanf(" %d", &N)) {
        limpa();

        char peca, coluna, linha;
        for (int i=0; i<N; i++) {
            scanf(" %c %c %c", &peca, &coluna, &linha);
            tabuleiro[linha-'1'][coluna-'a'] = peca;
        }

        scanf(" %c %c %c", &peca, &coluna, &linha);
        // tabuleiro[linha-'1'][coluna-'a'] = '&';
        //showTabuleiro();
        bool is_safe = false;

        for (int curr_move = 0; curr_move <= 8; curr_move++) {
            int king_i = linha-'1';
            int king_j = coluna-'a';
            moveMyKing(king_i, king_j, curr_move);
            is_safe = is_safe || !isReiCheck(king_i, king_j);
        }
        printf(!is_safe? "SIM\n" : "NAO\n");
    }


    return 0;
}
