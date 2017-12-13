/*
 * Matheus Oliveira
 * 26/08/2017
 * 1587.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 2000005
#define MAXPL 1500000

int team_a[MAXPL], team_b[MAXPL];
long long int fenwick_a[MAXN], fenwick_b[MAXN], jogadores;

void update(long long int fenwick[], int index, int value) {
	index += 1;

	while(index <= MAXN) {
		fenwick[index] += value;
		index += index & (-index);
	}
}

long long int read(long long int fenwick[], int index) {

	index += 1;
	if(index <= 0 or index > 2000001) return 0;

	long long int sum = 0;

	while(index > 0) {
		sum += fenwick[index];
		index -= index & (-index);
	}

	return sum;
}

int main() {

	int eventos, i, pos, taxa, total, gols_b, gols_a, pl;
	long long int a_frente;
	double calculo;

	char op, team;
	bool valendo;

	while(cin >> jogadores >> eventos) {
		calculo = jogadores / 11.0;
		taxa = ceil(calculo);

		if(jogadores == 0 and eventos == 0) break;

		valendo = true;
		gols_a = gols_b = 0;

		memset(fenwick_a, 0, sizeof(fenwick_a));
		memset(fenwick_b, 0, sizeof(fenwick_b));

		for(i=0; i < jogadores/2; i++) {
			cin >> pos;

			team_a[i+1] = pos;
			update(fenwick_a, pos, 1);
		}

		for(i=0; i < jogadores/2; i++) {
			cin >> pos;

			team_b[i+1] = pos;
			update(fenwick_b, pos, 1);
		}

		for(i=0; i < eventos; i++) {
			cin >> op;

			if(op == 'I') {
				cin >> team >> pl;

				if(team == 'A') {
					a_frente = read(fenwick_b, team_a[pl]);
					if( (jogadores/2) - a_frente < taxa ) valendo = false;
				}
				else {
					a_frente = read(fenwick_a, team_b[pl]-1);
					if( a_frente < taxa) valendo = false;
				}
			}

			if(op == 'M') {
				cin >> team >> pl >> pos;

				if(team == 'A') {
					update(fenwick_a, team_a[pl], -1);
					team_a[pl] = pos;
					update(fenwick_a, team_a[pl], 1);
				}
				else {
					update(fenwick_b, team_b[pl], -1);
					team_b[pl] = pos;
					update(fenwick_b, team_b[pl], 1);
				}
			}

			if(op == 'P') {
				cin >> team >> pl;

				if(team == 'A') {
					a_frente = read(fenwick_b, team_a[pl]);
					if( (jogadores/2) - a_frente < taxa ) valendo = false;
				}
				else {
					a_frente = read(fenwick_a, team_b[pl]-1);
					if( a_frente < taxa) valendo = false;
				}
			}	

			if(op == 'G') {
				cin >> team;

				if(valendo) {
					if(team == 'A') gols_b++;
					else gols_a++;
				}
				else valendo = true;
			}

			if(op == 'S') valendo = true;
		}

		printf("%d X %d\n", gols_a, gols_b);
	}

	return 0;
}
