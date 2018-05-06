#include <bits/stdc++.h>

using namespace std;

const size_t MAXN = 123;

class Node {
public:
    int left, right;
    Node() : left(0), right(0) {}
    Node(int left, int right) : left(left), right(right) {}
};

Node cell[MAXN];
vector<Node> segments;
bitset<MAXN> visited;

int walkLeft(int node){
    visited[node] = 1;
    if (cell[node].left == 0) return node;
    return walkLeft(cell[node].left);
}

int walkRight(int node){
    visited[node] = 1;
    if (cell[node].right == 0) return node;
    return walkRight(cell[node].right);
}

void transverse(int node){
    segments.push_back({walkLeft(node), walkRight(node)});
    visited[node] = 1;
}

void connectSegments(int first, int second){
    cell[first].right = second;
    cell[second].left = first;
}

int main(){
    int N;
    scanf(" %d", &N);

    for (int i=1; i<=N; i++){
        scanf(" %d %d", &cell[i].left, &cell[i].right);
    }

    for (int i=1; i<=N; i++){
        if (!visited[i]) transverse(i);
    }

    for (int i=0; i+1<segments.size(); i++){
        connectSegments(segments[i].right, segments[i+1].left);
    }

    for (int i=1; i<=N; i++){
        printf("%d %d\n", cell[i].left, cell[i].right);
    }

    return 0;
}
