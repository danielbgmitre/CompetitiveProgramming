#include <bits/stdc++.h>

using namespace std;

const int MAXN = 81;

int gcd(long long a, long long b) {
    return b==0? a : gcd(b, a%b);
}

int lcm(long long a, long long b) {
    return (a*b)/gcd(a, b);
}

struct atraction {
    int popular;
    int visited;
    int idx;
    atraction()
    : popular(0), visited(0), idx(0) {}
    atraction(int popular, int visited, int idx)
    : popular(popular), visited(visited), idx(idx) {}

    bool operator < (const atraction &b) {
        if (visited == b.visited) return popular > b.popular;
        return visited < b.visited;
    }
};

set<int> solve(int N, int K, int V) {
    vector<atraction> count;
    count.resize(N);

    for (int i=0; i<N; i++){
        count[i].idx = i;
        count[i].popular = N-i;
        count[i].visited = 0;
    }

    while (V >= 0) {
        sort(count.begin(), count.end());
        for (int i=0; i<K; i++) {
            //cout << "visitei "<<count[i].idx<<endl;
            count[i].visited++;
        }
        V--;
    }

    set<int> ans;
    for (int i=0; i<K; i++) {
        //cout << "devo visitar "<<count[i].idx<<endl;
        ans.insert(count[i].idx);
    }

    return ans;
}

int main() {
    int T;
    scanf(" %d", &T);

    for (int t=1; t<=T; t++) {
        int N, K;
        long long V;
        scanf(" %d %d %lld", &N, &K, &V);
        //cout << "lcm("<<N<<", "<<K<<") = "<<lcm(N, K)<<endl;
        V--;
        V = V%lcm(N, K);

        char words[MAXN][100000];

        for (int i=0; i<N; i++) {
            scanf(" %99999s", words[i]);
            //cout << "li uma palavra"<<endl;
            //words[i] = temp;
        }

        set<int> res = solve(N, K, V);

        printf("Case #%d:", t);
        for (int idx : res) {
            printf(" %s", words[idx]);
        }
        printf("\n");
    }

    return 0;
}
