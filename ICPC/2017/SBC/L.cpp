// https://www.urionlinejudge.com.br/judge/pt/problems/view/2669
// Laboratório de Biotecnologia
// Getting 5% WA on URI, but matches output for all contest inputs
// so it's probabilly a MLE problem

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 8388608;//4194304;
const int MAXPOW = 24;
const double PI = acos(-1);
const double TWOPI = 2*PI;

struct cpx {
  double r, i;
  cd(double r, double i) : r(r), i(i) {}
  cd() : r(0), i(0) {}
  cd(int x, int i) : r(x), i(i) {}
};

int pow_2[MAXPOW];
int pow_4[MAXPOW];

vector<int> result;
vector<int> pr_sum;
cpx* a,* b;

void twiddle(cpx &W, double N, double v){
    W.r = cos(v * TWOPI / N);
    W.i = -sin(v * TWOPI / N);
}

void radix4_reorder(cpx W[], int N) {
    int bits=23;
    double tempr, tempi;

    for (int i=0; i<N; i++) {
        int j=0;
        for (int k=0; k<bits; k+=2) {
            if (i&pow_2[k])   j += pow_2[bits-k-2];
            if (i&pow_2[k+1]) j+= pow_2[bits-k-1];
        }
        if (j > i){
            tempr = W[i].r, tempi = W[i].i;
            W[i].r = W[j].r, W[i].i = W[j].i;
            W[j].r = tempr, W[j].i = tempi;
        }
    }
}

//radix4 fft
void fft(cpx x[], int N) {
    int N1 = 4;
    int N2 = N/4;

    for (int n2=0; n2<N2; n2++) {
	/** Don't hurt the butterfly */
    	bfly[0].r = (x[n2].r + x[N2 + n2].r + x[2*N2+n2].r + x[3*N2+n2].r);
    	bfly[0].i = (x[n2].i + x[N2 + n2].i + x[2*N2+n2].i + x[3*N2+n2].i);

    	bfly[1].r = (x[n2].r + x[N2 + n2].i - x[2*N2+n2].r - x[3*N2+n2].i);
    	bfly[1].i = (x[n2].i - x[N2 + n2].r - x[2*N2+n2].i + x[3*N2+n2].r);

    	bfly[2].r = (x[n2].r - x[N2 + n2].r + x[2*N2+n2].r - x[3*N2+n2].r);
    	bfly[2].i = (x[n2].i - x[N2 + n2].i + x[2*N2+n2].i - x[3*N2+n2].i);

    	bfly[3].r = (x[n2].r - x[N2 + n2].i - x[2*N2+n2].r + x[3*N2+n2].i);
    	bfly[3].i = (x[n2].i + x[N2 + n2].r - x[2*N2+n2].i - x[3*N2+n2].r);


    	/** In-place results */
    	for (int k1=0; k1<N1; k1++) {
    	    twiddle(W, N, (double)k1*(double)n2);
    	    x[n2 + N2*k1].r = bfly[k1].r*W.r - bfly[k1].i*W.i;
    	    x[n2 + N2*k1].i = bfly[k1].i*W.r + bfly[k1].r*W.i;
    	}
    }

    if (N2 != 1) {
        for (int k1=0; k1 < N1; k1++) {
            radix4(&x[N2*k1], N2);
        }
    }
}

void showVec(vector<int> const& v, string name) {
    cout << name << " = [ ";
    for (int el : v) {
        cout << el << " ";
    }
    cout << "] "<< endl;
}


int main() {
    pr_sum.resize(MAXN);
    a = new cpx[MAXN];
    b = new cpx[MAXN];
    pr_sum[0] = 0;
    int n = 1;

    char c;
    while (~scanf(" %c", &c)) {
        pr_sum[n] = c - 'a' + 1 + pr_sum[n-1];
        n++;
    }

    //a.resize(MAXN), b.resize(MAXN), result.resize(MAXN);
    const int total = pr_sum[n-1];

    a.resize(total+1), b.resize(total+1);

    for (int i=0; i<n; i++) {
        a[pr_sum[i]].r = 1;
        b[total - pr_sum[i]].r = 1;
    }

    multiply(a, b);

    unsigned long long int res = 0;
    for (int i = total+1; i < result.size(); i++) {
        if (result[i] >= 1) {
            res++;
        }
    }

    printf("%llu\n", res);

    return 0;
}
