#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

inline int compact(unordered_map<int, int>& comp, int v) {
    if (!comp.count(v)) {
        comp[v] = comp.size();
    }
    return comp[v];
}



int main() {
    int N;
    while (scanf(" %d", &N) && N != 0) {
        set<vector<pii>> res;
        for (int i=0; i<N; i++) {
            unordered_map<int, int> comp;
            int faces[6];
            for (int f=0; f<6; f++)  {
                scanf(" %d", &faces[f]);
            }
            for (int f=0; f<6; f++) {
                faces[f] = compact(comp, faces[f]);
            }
            vector<pii> opostos;

            if (faces[0] > faces[5]) {
                swap(faces[0], faces[5]);
            }
            opostos.emplace_back(faces[0], faces[5]);
            if (faces[1] > faces[3]) {
                swap(faces[1], faces[3]);
            }
            opostos.emplace_back(faces[1], faces[3]);
            if (faces[2] > faces[4]) {
                swap(faces[2], faces[4]);
            }
            opostos.emplace_back(faces[2], faces[4]);
            sort(opostos.begin(), opostos.end());

            res.insert(opostos);
        }
        printf("%lu\n", res.size());
    }

    return 0;
}
