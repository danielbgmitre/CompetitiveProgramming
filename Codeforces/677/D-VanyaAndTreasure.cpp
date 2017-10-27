//http://codeforces.com/problemset/problem/677/D
//Vanya .y Treasure

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 333;
const int INF  = 999999999;

#define x first
#define y second

typedef pair<int, int> ii;
typedef pair<int, pair<int, int>> iii;

int grid[MAXN][MAXN], dp[MAXN][MAXN];
vector<ii> atalhos[MAXN*MAXN];

int andaX[] = {0, 0, 1, -1};
int andaY[] = {1, -1, 0, 0};

void bfs(int color, int N, int M){
	queue<ii> fila;

	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			if (grid[i][j] == color){
				fila.push({i, j});
			} else {
				dp[i][j] = INF;
			}
		}
	}

	while (!fila.empty()){
		ii pos = fila.front(); fila.pop();

		for (int i=0; i<4; i++){
			int a = pos.x + andaX[i];
			int b = pos.y + andaY[i];
			if (a >= 1 && a <= N && b >= 1 && b <= M &&
					dp[a][b] > dp[pos.x][pos.y] + 1){
				dp[a][b] = dp[pos.x][pos.y] + 1;
				fila.push({a, b});
			}
		}
	}

	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			if (grid[i][j] != color+1){
				dp[i][j] = INF;
			}
		}
	}
}

int main(){
	int N, M, P;
	scanf(" %d %d %d", &N, &M, &P);
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			scanf(" %d", &grid[i][j]);
			atalhos[grid[i][j]].push_back({i, j});
		}
	}

	for (int i=0; i<=N; i++)
		for (int j=0; j<=M; j++)
			dp[i][j] = INF;

	for (int color=1; color <= P; color++){
		if (atalhos[color-1].size()*atalhos[color].size() < N*M){
			for (ii pos : atalhos[color]){
				if (color == 1) {
					dp[pos.x][pos.y] = pos.x+pos.y-2;
				} else {
					for (ii prev : atalhos[color-1]){
						dp[pos.x][pos.y] = min(dp[pos.x][pos.y],
						    dp[prev.x][prev.y] + abs(prev.x-pos.x) + abs(prev.y-pos.y));
					}
				}
			}
		} else {
			bfs(color-1, N, M);
		}
	}

	int res = INF;
	for (ii pos : atalhos[P]){
		res = min(res, dp[pos.x][pos.y]);
	}
	printf("%d\n", res);

	return 0;
}
