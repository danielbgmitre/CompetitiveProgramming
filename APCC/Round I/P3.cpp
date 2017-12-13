/*
 * Matheus Oliveira
 * 19/08/2017
 * 1514.cpp
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

struct probs {
	bitset<105> problemas;
} infos[MAXN];

int main () {

	int competidores, probs, i, j, status, score[5], ans;
	bool resolveu_alguma, errou_alguma;

	while(scanf("%d %d", &competidores, &probs)) {

		if(competidores == 0 and probs == 0) break;
		memset(score, 0, sizeof(score)); // 0 = tem p, -1 = nao tem

		for(j=0; j < probs; j++) infos[j].problemas.reset();

		for(i=0; i < competidores; i++) {
			resolveu_alguma = errou_alguma = false;

			for(j=0; j < probs; j++) {

				scanf("%d", &status);

				if(status == 1) resolveu_alguma = true, infos[j].problemas.set(i);
				else errou_alguma = true;
			}

			if(errou_alguma and !resolveu_alguma) score[4] = -1;
			if(resolveu_alguma and !errou_alguma) score[1] = -1;
		}

		for(j=0; j < probs; j++) {
			if(infos[j].problemas.count() == competidores) score[3] = -1;
			if(infos[j].problemas.count() == 0) score[2] = -1;
		}

		ans = 0;
		for(i=1; i <= 4; i++) if(score[i] == 0) ans++;
		printf("%d\n", ans);
	}

	return 0;
}
