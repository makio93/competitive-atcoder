// 復習2回目,解説AC2

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    double p;
    cin >> p;
    auto f = [&](double x) -> double {
        return x + p * 1.0 / pow(2.0, x/1.5);
    };
    auto fp = [&](double x) -> double {
        return -p*log(2.0)*pow(2.0,-x/1.5)/1.5 + 1.0;
    };
    if (fp(0.0) >= 0.0) {
        printf("%.10f\n", f(0.0));
        return 0;
    }
    double l = 0.0, r = p;
    while (r-l >= 1e-9) {
        double c = (l+r) / 2.0;
        if (fp(c) >= 0.0) r = c;
        else l = c;
    }
    printf("%.10f\n", f(l));
    return 0;
}
