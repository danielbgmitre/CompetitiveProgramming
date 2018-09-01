#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int possibles_sz = 0;

int possibles[MAXN];
int sticks[MAXN];

void counting_sort(int N) {
    map<int, int> freq;

    for (int i=0; i<N; i++) {
        freq[sticks[i]]++;
    }

    for (auto &p : freq) {
        while (p.second >=2) {
            possibles[possibles_sz++] = p.first;
            p.second -= 2;
        }
    }
}

long long perimeter(int a, int b) {
    return a*2 + b*2;
}

long long area(int a, int b) {
    return (a*b);
}

int main() {
    int T;
    scanf(" %d", &T);

    for (int teste=0; teste<T; teste++) {
        //possibles.clear();
        possibles_sz = 0;
        int N;
        scanf(" %d", &N);

        for (int i=0; i<N; i++) {
            scanf(" %d", &sticks[i]);
        }

        counting_sort(N);

        double best = numeric_limits<double>::infinity();
        pair<int, int> ans = make_pair(-1, -1);

        for (int i=0; i<possibles_sz-1; i++) {
            double temp = (perimeter(possibles[i], possibles[i+1]) * perimeter(possibles[i], possibles[i+1]));
            temp /= area(possibles[i], possibles[i+1]);
            if (temp < best) {
                best = temp;
                ans = make_pair(possibles[i], possibles[i+1]);
            }
        }

        //cout << "res: "<<best<<endl;
        printf("%d %d %d %d\n", ans.first, ans.first, ans.second, ans.second);
    }

    return 0;
}
