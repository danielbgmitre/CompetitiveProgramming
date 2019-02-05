#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> freq;

void fast_stdio(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int cost_of(string word) {
    bitset<20> hands;

    int cost = 0;
    for (int i=0; i<word.size(); i++) {
        hands[i] = (word[i] == 'd') || (word[i] == 'f');
        if ((i == 0) || (hands[i] != hands[i-1])) {
            cost += 2;
        } else {
            cost += 4;
        }
    }
    return cost;
}

int main() {
    fast_stdio();

    int T;
    cin >> T;

    for (int teste=0; teste < T; teste++) {
        freq.clear();

        int N;
        cin >> N;

        string word;
        for (int i=0; i<N; i++) {
            cin >> word;
            freq[word]++;
        }

        long long total = 0;
        for (auto& p : freq) {
            long long cost = cost_of(p.first);
            total += cost + ((cost * (p.second - 1LL)) >> 1);
        }
        cout << total << endl;
    }

    return 0;
}
