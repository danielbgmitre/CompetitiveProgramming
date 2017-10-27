//https://www.urionlinejudge.com.br/judge/pt/problems/view/1661
//Comercio de Vinhos na Gergóvia

#include <bits/stdc++.h>

using namespace std;

int main(){
	int N, vinhos;
	while (scanf(" %d", &N) && N != 0){
		long long int res = 0, acum = 0;
		for(int i=0; i<N; i++){
			scanf(" %d", &vinhos);
			res += abs(acum);
			acum += vinhos;
		}
		printf("%lld\n", res);
	}
	return 0;
}
