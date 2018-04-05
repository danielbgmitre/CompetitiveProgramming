//http://acm.timus.ru/problem.aspx?space=1&num=1052
//Rabbit Hunt

#include <bits/stdc++.h>

using namespace std;

const double PI  = 180/3.14159265359;
const double EPS = 1e-9;

struct point {
    double x, y, z;

    double modulo(){
        return sqrt(x*x + y*y + z*z);
    }

    point operator - (const point& other) const{
        point res;
        res.x = this->x-other.x;
        res.y = this->y-other.y;
        res.z = this->z-other.z;
        return res;
    }
};

double vetorial(const point &a, const point &b){
    return -(a.x * b.y - a.y * b.x);
}

bool double_equals(double n1, double n2){
    if (abs(n2-n1) <= EPS){
        return true;
    }
    return false;
}

vector<point> coelhos;

int main() {
	int N, x, y;

	scanf(" %d", &N);

	int count = 0;
	for (int i=0; i<N; i++){
        point p;
		scanf(" %d %d", &x, &y);
        p.x = x;
        p.y = y;
		coelhos.push_back(p);
	}

	int max_res = 0;
	for (int i = 0; i<N; i++){
        for (int j = i+1; j<N; j++){
            int res = 2;
            for (int k = j+1; k<N; k++){
                point p1, p2;
                p1 = coelhos[j]-coelhos[i];
                p2 = coelhos[k]-coelhos[i];
                if (double_equals(0, vetorial(p1, p2))){
                    res++;
                }

            }
            max_res = max(max_res, res);
        }
		//printf("%.d\n", c.first);
	}


	printf("%d\n", max_res);
	return 0;
}
