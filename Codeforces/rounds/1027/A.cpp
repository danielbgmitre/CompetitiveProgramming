#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;

int main() {
    int T;
    scanf(" %d", &T);

    int N;
    char word[MAXN];
    for (int teste=0; teste<T; teste++) {
        scanf(" %d", &N);
        scanf(" %s", word);

        int half = N/2;
        bool palindrome = true;
        int distance;
        for (int i=0; i<half; i++) {
            distance = abs(word[N-i-1]-word[i]);
            if (distance != 0 && distance != 2) {
                palindrome = false;
            }
        }
        if (!palindrome) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }


    return 0;
}
