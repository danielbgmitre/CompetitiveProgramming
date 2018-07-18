#include <bits/stdc++.h>

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();
    int i=0;
    auto now = chrono::high_resolution_clock::now();
    while (chrono::duration_cast<chrono::milliseconds>(now-start).count() < 1000) {
        i++;
        now = chrono::high_resolution_clock::now();
    }
    cout << i << endl;
}
//16_018_399    = 1seg
//4_805_519_700 = 5min
