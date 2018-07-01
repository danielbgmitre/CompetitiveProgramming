#include <bits/stdc++.h>

using namespace std;

int freq[11];
string number;

long long int factorial(int N){
    if (N <= 1) return 1;
    else {
        return factorial(N-1) * N;
    }
}

int main() {
    cin >> number;
    long long total_numbers=0;
    for (size_t i=0; i<number.size(); i++){
        freq[number[i]-'0']++;
        total_numbers++;
    }

    long long repetidas = 0;
    for (int i=0; i<10; i++) {
        repetidas += max(0, freq[i]-1);
    }

    long long diferentes = total_numbers-repetidas;


    long long res = 0;

    long long starting = diferentes-min(freq[0], 1);
    for (int i=0; i<=repetidas; i++){
        long long possibles = starting*factorial(diferentes+i);
        possibles /= factorial(i)*factorial();
        res += possibles;
    }

    cout << res << endl;


    return 0;
}
