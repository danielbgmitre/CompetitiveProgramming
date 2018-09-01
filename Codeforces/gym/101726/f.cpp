#include <bits/stdc++.h>
#define MAXN 102
#define f first
#define s second
using namespace std;

int alt[MAXN];

const double PI = acos(-1.0);

struct Vetor {
    int x, y;

    Vetor () : x(0), y(0) {}

    Vetor (int _x, int _y) : x(_x), y(_y) {}
};

struct Point{
    int x, y;

    Point () : x(0), y(0) {}

    Point (int _x, int _y) : x(_x), y(_y) {}
};

Vetor toVetor (Point a, Point b){
    return Vetor(b.x-a.x, b.y-a.y);
}

pair <Point, Point> predios[MAXN];

double pe(Vetor a, Vetor b){
    return a.x * b.x + a.y * b.y;
}

double norma(Vetor a){
    return pe(a, a);
}

double angle(Point a, Point o, Point b){
    Vetor oa = toVetor(o, a);
    Vetor ob = toVetor(o, b);

    return acos(pe(oa, ob) / sqrt(norma(oa) * norma(ob)));
}

int main(){
    int t, n;

    scanf("%d", &t);

    while(t--){

        int n, w, s;
        scanf("%d %d %d", &n, &w, &s);

        int jar = -1;
        int xTotal = 0;
        for (int i=0; i<n; i++){
            scanf("%d", &alt[i]);
            predios[i].f = Point(xTotal, alt[i]);
            xTotal += w;
            predios[i].s = Point(xTotal, alt[i]);
            xTotal += s;
            if (alt[i] == 0){
                jar = i;
            }
        }

        double angl = 0;
        double angr = 0;
        for (int i=jar-1; i>=0; i--){
            angl = max(angl, angle(predios[jar].f, predios[jar].s, predios[i].s));
        }

        for (int i=jar+1; i<n; i++){
            angr = max(angr, angle(predios[jar].s, predios[jar].f, predios[i].f));
        }

        double angRes = PI - angl - angr;

        double res = (angRes * 16.0 * 60) / PI;

        printf("%.8f\n", res);
    }


    return 0;
}
