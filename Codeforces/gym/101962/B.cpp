#include <bits/stdc++.h>

using namespace std;

string room, sofa;

bool solve(int start, int end, bool reverse=false) {
    char color[2] = {0, 0};

    int s = reverse ? sofa.size() - 1 : 0;

    for (int r = start; r < end; r++) {
        if (color[sofa[s]] == 0) {
            color[sofa[s]] = room[r];

        } else if (color[sofa[s]] != room[r]) {
            return false;
        }
        reverse ? s-- : s++;
    }

    return true;
}

int main() {
    cin >> room >> sofa;

    for (size_t i=0; i < sofa.size(); i++) {
        sofa[i] -= '0';
    }

    int res = 0;
    for (size_t i=0; i + sofa.size() <= room.size(); i++) {
        res += solve(i, i + sofa.size()) || solve(i, i + sofa.size(), true);
    }

    printf("%d\n", res);

    return 0;
}
