#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
double grades[MAXN];

template <class T> class FenwickTree {
public:
    T* BIT;
    size_t size;

    FenwickTree(size_t size, T default_value) : size(size) {
        BIT = new T[size];
        for (size_t i=0; i<size; i++){
            BIT[i] = default_value;
        }
    }

    T sum(size_t idx){
        T total = 0;
        while (idx>0){
            total += BIT[idx];
            idx -= idx & (-idx);
        }
        return total;
    }

    T sum(size_t from, size_t to){
        return sum(to)-sum(from-1);
    }

    void add(size_t idx, T v){
        while (idx < size) {
            BIT[idx] += v;
            idx += idx & (-idx);
        }
    }
};

FenwickTree<double> BIT(MAXN, 0.0);

int main() {
    int N;
    scanf(" %d", &N);

    for (int i=1; i<=N; i++){
        scanf(" %lf", &grades[i]);
        BIT.add(i, grades[i]);
    }

    int Q;
    scanf(" %d", &Q);

    int op, pos1, pos2;
    double new_grade;
    while (Q--){
        scanf(" %d", &op);
        if (op == 1) {
            scanf(" %d %lf", &pos1, &new_grade);
            BIT.add(pos1, new_grade - grades[pos1]);
            grades[pos1] = new_grade;
        } else {
            scanf(" %d %d", &pos1, &pos2);
            printf("%.8lf\n", BIT.sum(pos1, pos2)/(pos2-pos1+1));
        }
    }

    return 0;
}
