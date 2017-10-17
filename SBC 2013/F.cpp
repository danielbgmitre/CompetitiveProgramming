#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000 ;

bool compara(int a, double b){
	return (abs(b-a) < 0.000000000001);
}

int main(){
	int N;
	while (scanf(" %d", &N) != EOF){
		int pontos[MAXN], perimetro = 0;
		
		unordered_map<int, int> dists;
		
		for (int i=0; i<N; i++){
			scanf(" %d", &pontos[i]);
			perimetro += pontos[i];
		}
		
		int acum = 0;
		for (int i=0; i<N; i++){
			acum = (acum+pontos[i])%perimetro;
			dists[acum] = 1;
		}
		int lado = perimetro/3;
		if (!compara(perimetro/3, perimetro/3.0)){
			printf("0\n"); continue;
		} else {
			int res = acum = 0;
			for (int i=0; i<N; i++){
				acum = (acum+pontos[i])%perimetro;
				if (dists.count((acum+lado)%perimetro) && dists.count((acum+lado+lado)%perimetro)){
					res++;
				}
			}
			printf("%d\n", res/3);
		}
	}
	
	
	return 0;
}
