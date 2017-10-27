//https://www.urionlinejudge.com.br/judge/pt/problems/view/2115
//Produção em Ecaterimburgo

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

typedef pair<int, int> ii;

ii tarefas[MAXN];

int main(){
	int N;
	while (scanf(" %d", &N) != EOF){
		for (int i=0; i<N; i++){
			scanf(" %d %d", &tarefas[i].first, &tarefas[i].second);
		}

		sort(tarefas, tarefas+N);
		int res = 1;
		for (int i=0; i<N; i++){
			if (tarefas[i].first > res){
				res = tarefas[i].first;
			}
			res += tarefas[i].second;
		}
		printf("%d\n", res);

	}
	return 0;
}
