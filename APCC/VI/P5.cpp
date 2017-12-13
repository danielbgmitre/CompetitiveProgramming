/*
 * Matheus Oliveira
 * 29/10/2017
 * 1930.cpp
*/

/* Breve comentário sobre o problema e sua solução:
 * P5 (Ivan's Car):
 * Basicamente, a ideia do problema era modificar o algoritmo de Dijkstra de maneira
 * a encontrar o melhor caminho nessa dada situação. A diferença aqui é que, ao invés de custos
 * por arestas, de uma cidade a outra, só devemos verificar quantas vezes Ivan mudou a marcha do carro.
 * É dito no problema que o carro tem 2 marchas, uma para descer ladeiras e outra para subir.
 * Assim, devemos modificar o dijkstra de maneira a somar 1 ao peso sempre que estamos mudando de uma marcha
 * para outra durante o percurso, e no fim, bastava exibir a distância do ponto inicial ao final.
 * A complexidade dela ficaria a de um Dijkstra otimizado, O(E * log(V)).
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define INF 1e9

typedef pair<int, int> P;

int distancias[MAXN], visited[MAXN];
vector< P > graph[MAXN];

int main() {

	int nodes, arestas, i, c1, c2, ini, fim, atual, aux, somar;
	scanf("%d %d", &nodes, &arestas);

	for(i=1; i <= nodes; i++) distancias[i] = INF;

	for(i=0; i < arestas; i++) {
		scanf("%d %d", &c1, &c2);

		graph[c1].push_back( make_pair(1, c2) );
		graph[c2].push_back( make_pair(0, c1) );
	}

	scanf("%d %d", &ini, &fim);

	priority_queue< pair<P, int>, vector< pair<P, int> >, greater< pair<P, int> > > djikstra;
	djikstra.push( make_pair( make_pair(0, ini), -1 ) );

	distancias[ini] = 0;

	while(not djikstra.empty()) {
		pair<P, int> atual = djikstra.top();
		djikstra.pop();

		int node = atual.first.second, dist = atual.first.first, neighbors = graph[node].size();
		int sentido = atual.second;

		// subindo = 1, desc = 0

		if(visited[node] == 1) continue;
		visited[node] = 1;

		for(i=0; i < neighbors; i++) {
			int neighbor = graph[node][i].second, dir = graph[node][i].first;

			if(sentido == -1) sentido = dir;

			if(visited[neighbor] == 0) {

				if(dir == sentido) somar = 0;
				else somar = 1;

				if(distancias[neighbor] > somar + dist) {
					distancias[neighbor] = somar + dist;
					djikstra.push( make_pair( make_pair(distancias[neighbor], neighbor), dir ) );
				}
			}
		}
	}

	printf("%d\n", distancias[fim]);

	return 0;
}
