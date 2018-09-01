#include <bits/stdc++.h>

using namespace std;

#define SPADES 's'
#define HEARTS 'h'
#define DIAMONDS 'd'
#define CLUBS 'c'

int realValue[1000];

struct card {
    char type, value;
    card(char t, char v) : type(t), value(v) {}
    int getValue(){
        return realValue[value-'0'];
    }
};

struct player {
    card card1, card2;
}

int main() {
    int T;
    scanf(" %d", &T);

    card card1_p1, card2_p1, card1_p2, card2_p2;
    card card1_mesa, card2_mesa, card3_mesa;

    for (int t=0; t<T; t++) {
        scanf(" %c %c", card)
    }


    return 0;
}
