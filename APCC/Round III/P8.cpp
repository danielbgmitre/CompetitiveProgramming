/*
 * Matheus Oliveira
 * 13/10/2017
 * 2357.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010

typedef pair<int, int> P;

vector<int> graph[MAXN];
int rank1[MAXN], pai[MAXN];

int read(int node) {

	if(pai[node] == -1) return node;
	return pai[node] = read(pai[node]);
}

void join(int n1, int n2) {

	int s1 = read(n1), s2 = read(n2);
	if(s1 == s2) return;

	if(rank1[s1] > rank1[s2]) pai[s2] = s1;
	else if(rank1[s1] < rank1[s2]) pai[s1] = s2;
	else {
		pai[s1] = s2;
		rank1[s2]++;
	}
}

int main () {

	int nodes, edges, i, s1, s2, n1, n2;
	bool seguro;
	multiset< P > checar;
	
	while(scanf("%d %d", &nodes, &edges) != EOF) {

		for(i=0; i <= nodes; i++) pai[i] = -1, graph[i].clear(), rank1[i] = 0;
		checar.clear();

		for(i=0; i < edges; i++) {
			scanf("%d %d", &n1, &n2);

			P testar;
			testar.first = min(n1, n2), testar.second = max(n1, n2);

			graph[n1].push_back(n2);
			graph[n2].push_back(n1);

			checar.insert(testar);
		}

		seguro = true;

		while(checar.size() > 0) {
			P atual = (*checar.begin());
			checar.erase(checar.begin());

			if(!seguro) continue;

			n1 = atual.first, n2 = atual.second;
			s1 = read(n1), s2 = read(n2);

			//printf("n1 = %d, s1 = %d, n2 = %d, s2 = %d\n", n1, s1, n2, s2);

			if(s1 == s2) {
				seguro = false;
				continue;
			}
			else join(n1, n2);
		}

		if(seguro) printf("Seguro\n");
		else printf("Inseguro\n");

		//cout << checar.size() << endl;
	}

	return 0;
}
