/*
 * Building a Field
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/2904
 * O(n.log(n)) solution
 */

#include <bits/stdc++.h>

using namespace std;

unordered_set<int> trees;

int main() {
    int N;
    scanf(" %d", &N);

    int tam = 0;
    int temp;
    for (int i=0; i<N; i++) {
        trees.insert(tam);
        scanf(" %d", &temp);
        tam += temp;
    }

    if (tam % 2) {  // is odd
        printf("N\n");
        return 0;
    }

    const int half = tam / 2;

    int crosses = 0;
    for (int tree : trees) {
        crosses += (trees.count((tree + half) % tam));
    }

    if (crosses >= 4) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}
