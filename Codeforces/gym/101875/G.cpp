#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 100;

pair<double, double> cars[MAXN];

#define vel second
#define pos first

int main() {
    int N;
    scanf(" %d", &N);

    for(int i=0; i<N; i++ ) {
        scanf("%lf %lf", &cars[i].pos, &cars[i].vel);
    }
    sort(cars, cars+N);

    double last = 0.0;

    for (int i=N-2; i>=0; i--){
        if (cars[i+1].vel >= cars[i].vel) {
            continue;
        }
        double dt = cars[i].vel - cars[i+1].vel;
        double ds = cars[i+1].pos - cars[i].pos;

        double tempo = ds/dt;
        if (tempo > last) {
            last = tempo;
        }
        //cout << "o carro "<<i<<" colidira apos "<<tempo;
        //double new_pos = cars[i].pos + cars[i].vel * tempo;

        //cout << " e ficara em "<< new_pos <<endl;
        cars[i].vel = cars[i+1].vel;
        cars[i].pos = cars[i+1].pos;
    }

    printf("%.10lf\n", last);

    return 0;
}
