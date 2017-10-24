#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600;
const int INF  = 999999999;

void inicia(int N){
	
}

int main(){
	int N, M, I;
	while (scanf(" %d %d %d", &N, &M, &I) != EOF){
		int idades[MAXN];
		int menorchefe[MAXN];
		bool boss[MAXN][MAXN] = {false};
		
		for (int i=0; i<=N; i++){
			idades[i] = INF;
			menorchefe[i] = INF;
		}
		
		for (int i=1; i<=N; i++) scanf(" %d", &idades[i]);
		
		int x, y;
		for (int i=0; i<M; i++){
			scanf(" %d %d", &x, &y);
			boss[y][x] = true;
			menorchefe[y] = min(menorchefe[y], idades[x]);
			
		}
		
		char op;
		int arg1, arg2;
		for (int i=0; i<I; i++){
			scanf(" %c", &op);
			if (op == 'P'){
				scanf(" %d",  &arg1);
				printf("%d\n", menorchefe[arg1]);
			} else {
				scanf(" %d %d", &arg1, &arg2);
				int menorA = INF, menorB = INF;
				for (int chefe=1; chefe<=N; chefe++){
					if (boss[arg1][chefe]){
						swap(boss[arg1][chefe], boss[chefe][arg1]);
						swap(menorchefe[arg1], menorchefe[chefe]);
					}
				}
			}
		}
		
	}
	
	return 0;
}
