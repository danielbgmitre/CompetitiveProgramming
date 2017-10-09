//https://www.urionlinejudge.com.br/judge/pt/problems/view/1163
//Angry Ducks

#include <bits/stdc++.h>

using namespace std;

const double GRAVITY = -9.80665/2;
const double PI      =  3.14159/180;
const double EPS     =  1e-5;

//dY = Vy * dT + (a + (dT)²)/2
double distancia(double altura, double ang, double vel){
    double y_vel = sin(ang * PI) * vel;
    double x_vel = cos(ang * PI) * vel;

    //d = (-b + sqrt(b² - 4ac))/2a
    double delta = y_vel*y_vel - 4*GRAVITY*altura;
    double tempo  = (-y_vel - sqrt(delta))/(2*GRAVITY);

    return x_vel * tempo;
}

int main(){
    double h;
    while (scanf(" %lf", &h) != EOF){
        int n, limites[2];
        scanf(" %d %d %d", &limites[0], &limites[1], &n);
        sort(limites, limites+2);
        for (int i=0; i<n; i++){
            double ang, vel, res;
            scanf(" %lf %lf", &ang, &vel);

            res = distancia(h, ang, vel);
            printf("%.5lf -> ", res);

            if (res >= limites[0] && res <= limites[1]){
                printf("DUCK\n");
            } else {
                printf("NUCK\n");
            }
        }
    }
    return 0;
}
