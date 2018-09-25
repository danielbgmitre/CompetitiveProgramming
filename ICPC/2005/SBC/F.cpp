#include <bits/stdc++.h>

using namespace std;

int D;
long long S;

long long sum[10];
int path[10];
bitset<10> visited;

vector<vector<int>> adj = {
    {7, 8, 9},		//0
    {2, 4, 5},		//1
    {1, 3, 4, 5, 6},		//2
    {2, 5, 6},		//3
    {1, 2, 5, 7, 8},		//4
    {1, 2, 3, 4, 6, 7, 8, 9},	//5
    {2, 3, 5, 8, 9},		//6
    {0, 4, 5, 8},		//7
    {0, 4, 5, 6, 7, 9},		//8
    {0, 5, 6, 8}		//9
};

bool goesToZero(int i) {
    return (i == 7) || (i == 8) || (i == 9);
}

long long acum = 0LL;

char output[100];

void onFound(int len) {
    int pos, i;
    for (i = 0, pos = 0; i <= len; i++) {
        if (i > 0 && (i % D == 0))
            output[pos++] = ' ';
        output[pos++] = '0' + path[i];
    }

    output[pos] = '\0';
    puts(output);

    if (goesToZero(path[len]) && ((len % D) == (D-1)) && !visited[0]) {
        output[pos++] = ' ';
        output[pos++] = '0';
        output[pos] = '\0';
        puts(output);
    }
}

bool dfs(int curr, int k) {
    if (visited[curr] || k >= 10)
        return false;

    bool found = false;
    path[k] = curr;
    visited.set(curr);

    int bucket = k / D;

    if (k % D == 0)
        sum[bucket] = curr;
    else
        sum[bucket] = (sum[bucket] * 10) + curr;

    acum += sum[bucket];
    long long retirar = sum[bucket];

    if (acum == S) {
        //printf("resposta encontrada\n");
        onFound(k);
        found = true;
    }

    if (acum >= S) {
        acum -= sum[bucket];
        sum[bucket] /= 10;
        visited.reset(curr);
        return found;
    }

    if ((k % D) < (D - 1))
        acum -= sum[bucket];

    for (int tecla : adj[curr]) {
        found |= dfs(tecla, k+1);
    }

    if ((k % D) == (D-1))
        acum -= retirar;

    sum[bucket] /= 10;
    visited.reset(curr);

    return found;
}

int main() {
    int test = 1;
    while (scanf(" %lld %d", &S, &D) && !(S==-1 && D==-1)) {
        bool found = false;
        printf("#%d\n", test++);
        for (int i=0; i<10; i++) {
        	found |= dfs(i, 0);
        }
        if (!found)
            printf("impossivel\n");
    }

    return 0;
}
