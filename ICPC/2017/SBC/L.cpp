// https://www.urionlinejudge.com.br/judge/pt/problems/view/2669
// Laboratório de Biotecnologia
// Getting 5% WA on URI, but matches output for all contest inputs
// so it's probabilly a MLE problem

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4194304;
const double PI = acos(-1);

struct cd {
  double real, image;
  cd(double _real, double _image) {
    real = _real;
    image = _image;
  }
  cd() : real(0), image(0) {}
  cd(int x, int i) : real(x), image(i) {}
};

cd operator + (const cd &c1, const cd &c2) {
  return cd(c1.real + c2.real, c1.image + c2.image);
}

cd operator - (const cd &c1, const cd &c2) {
  return cd(c1.real - c2.real, c1.image - c2.image);
}

cd operator * (const cd &c1, const cd &c2) {
  return cd(c1.real*c2.real - c1.image*c2.image, c1.real*c2.image + c1.image*c2.real);
}

vector<int> result;
vector<int> pr_sum;
vector<cd> a, b;

void fft(vector<cd>& a, bool invert) {
    int n = a.size();

    for (int i=1, j=0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) {
            j ^= bit;
        }
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1, 0);
            for (int j = 0; j < len / 2; j++) {
                int left = i+j;
                int right = i+j+len/2;
                cd u = a[left], v = a[right] * w;
                a[left] = u + v;
                a[right] = u - v;
                w = w * wlen;
            }
        }
    }

    if (invert) {
        for (cd& x : a) {
            x.real /= n;
            x.image /= n;
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

void multiply(vector<cd>& fa, vector<cd>& fb) {
    int n = 1;
    while (n < fa.size() + fb.size()) {
        n <<= 1;
    }
    result.resize(n);

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i=0; i<n; i++) {
        fa[i] = fa[i] * fb[i];
    }
    fft(fa, true);

    for (int i=0; i<n; i++) {
        result[i] = (fa[i].real > .4);
    }
}

int main() {
    pr_sum.resize(MAXN);
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
        a[pr_sum[i]].real = 1;
        b[total - pr_sum[i]].real = 1;
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
