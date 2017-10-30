//http://acm.timus.ru/problem.aspx?space=1&num=1020
//Rope

#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second

const double PI = acos(-1);
const int MAXN = 105;

pair<double, double> nails[MAXN];

double dist(pair<double, double> v1, pair<double, double> v2){
	return sqrt(pow(v1.st - v2.st, 2) + pow(v1.nd - v2.nd, 2));
}

int main(){
	int N;
	double R;

	scanf(" %d %lf", &N, &R);
	for (int i=0; i<N; i++){
		scanf(" %lf %lf", &nails[i].st, &nails[i].nd);
	}

	pair<double, double> v1, v2;
	double res = 2 * PI * R;

	v1 = nails[0];
	for (int i=1; i<=N; i++){
		v2 = nails[i%N];
		res += dist(v1, v2);

		v1 = v2;
	}
	printf("%.2lf", res);


	return 0;
}
