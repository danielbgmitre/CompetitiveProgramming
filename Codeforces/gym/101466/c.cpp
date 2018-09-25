#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5050;

struct point {
    long long x, y, z;
    point() : x(0), y(0), z(0) {}
    point(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

bitset<MAXN> used;
point points[MAXN];

bool isInLine(point p1, point p2) {
    p1.x -= points[0].x;
    p1.y -= points[0].y;
    p1.z -= points[0].z;

    p2.x -= points[0].x;
    p2.y -= points[0].y;
    p2.z -= points[0].z;
    //
    // cout << "("<<p1.x << ", "<<p1.y<<", "<<p1.z<<") x ";
    // cout << "("<<p2.x << ", "<<p2.y<<", "<<p2.z<<") = ";

    long long x = (p1.y * p2.z) - (p1.z * p2.y);

    long long y = (p1.z * p2.x) - (p1.x * p2.z);

    long long z = (p1.x * p2.y) - (p1.y * p2.x);

    return (((x*x) + (y*y) + (z*z)) == 0);
}

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=0; i<N; i++) {
        scanf(" %lld %lld %lld", &points[i].x, &points[i].y, &points[i].z);
    }

    int res = 0;
    for (int i=1; i<N; i++) {
        if (!used[i]) {
            res++;
            used[i] = 1;
            // cout << "usando o ponto "<<i<<endl;
            for (int j=i; j<N; j++) {
                if (!used[j] && isInLine(points[i], points[j])) {
                    // cout << "cortei o ponto "<<j<<endl;
                    used[j] = 1;
                }
            }
        }
    }
    printf("%d\n", res);

    return 0;
}
