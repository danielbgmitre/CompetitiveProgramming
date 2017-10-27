//https://www.urionlinejudge.com.br/judge/pt/problems/view/1410
//Ele está impedido

#include <bits/stdc++.h>

using namespace std;

int main(){
	int A, D, def[30], ata[30];
	while (scanf(" %d %d", &A, &D) && !((A == D) && D == 0)){

		for (int i=0; i<A; i++){
			scanf(" %d", &ata[i]);
		}

		for (int i=0; i<D; i++){
			scanf(" %d", &def[i]);
		}

		sort(ata, ata+A);
		sort(def, def+D);

		if (ata[0] < def[1]){
			printf("Y\n");
		} else {
			printf("N\n");
		}
	}

	return 0;
}
