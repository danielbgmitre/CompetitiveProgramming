#include <bits/stdc++.h>
using namespace std;

vector <string> res;

int main(){
    int t, n;

    scanf("%d", &t);

    while(t--){

        scanf("%d", &n);

        res.clear();

        int tam = 0;

        for (int j = 0; j < 9; j++){
            int digit = n % 10;
            string digito = "";

            if (digit >= 5){
                digito += "01-";
                digit -= 5;
            } else {
                digito += "10-";
            }

            int indzero = digit;

            for (int i=0; i<6; i++){
                if (i == indzero){
                    digito += "0";
                } else {
                    digito += "1";
                }
            }

            res.push_back(digito);

            tam++;
            n /= 10;
        }

        for (int j=0; j<8; j++){
            for (int i=8; i>=0; i--){
                printf("%c", res[i][j]);
            }
            printf("\n");
        }

        if (t != 0) printf("\n");
    }


    return 0;
}
