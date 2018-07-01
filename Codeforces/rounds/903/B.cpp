//http://codeforces.com/contest/903/problem/B
//The Modcrab

#include <bits/stdc++.h>

using namespace std;

int simulate(int myHP, int myAtk, int potion, int monsHP, int monsAtk){
    int counter = 0;
    while (monsHP > 0){
        counter++;
        if (myAtk >= monsHP || myHP > monsAtk){
            monsHP -= myAtk;
            myHP -= monsAtk;
        } else {
            myHP += potion;
            myHP -= monsAtk;
        }
    }
    return counter;
}

int main(){
    int myHP, myAtk, potion;
    scanf(" %d %d %d", &myHP, &myAtk, &potion);

    int monsHP, monsAtk;
    scanf(" %d %d", &monsHP, &monsAtk);

    printf("%d\n", simulate(myHP, myAtk, potion, monsHP, monsAtk));
    while (monsHP > 0){
        if (myAtk >= monsHP || myHP > monsAtk){
            printf("STRIKE\n");
            monsHP -= myAtk;
            myHP -= monsAtk;
        } else {
            printf("HEAL\n");
            myHP += potion;
            myHP -= monsAtk;
        }
    }

    return 0;
}
