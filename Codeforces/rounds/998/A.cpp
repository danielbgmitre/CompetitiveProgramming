#include <bits/stdc++.h>

using namespace std;

pair<int, int> baloons[1010];

bool invCmp(const pair<int, int> &a, const pair<int, int> &b) {
    return b < a;
}

int main() {
    int N;
    scanf(" %d", &N);

    int total = 0;
    for (int i=0; i<N; i++) {
        scanf(" %d", &baloons[i].first);
        baloons[i].second = i+1;
        total += baloons[i].first;
    }

    if (N == 1) {
        printf("-1\n");
    } else if (N==2) {
        if (baloons[0].first == baloons[1].first) {
            printf("-1\n");
        } else {
            printf("1\n1\n");
        }
    } else {
        sort(baloons, baloons+N, invCmp);

        vector<int> ans;
        int actual = baloons[0].first;
        ans.push_back(baloons[0].second);
        for (int i=1; i<N; i++) {
            if (actual == total-actual) {
                actual += baloons[i].first;
                ans.push_back(baloons[i].second);
            } else {
                break;
            }
        }
        printf("%lu\n", ans.size());
        for (size_t i=0; i<ans.size(); i++) {
            printf((i+1==ans.size()) ? "%d\n" : "%d ", ans[i]);
        }
    }

    return 0;
}
