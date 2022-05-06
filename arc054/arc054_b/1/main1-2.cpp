// 

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
    double l = 0.0, r = p;
    auto f = [&](double t) -> double { return 1.5 * pow(2.0, t/1.5) - p * log(2.0); };
    while ((r-l)/r > 1e-8) {
        double c = l + (r-l) / 2.0;
        if (f(c) <= 0.0) l = c;
        else r = c;
    }
    printf("%.10f\n", l+p/pow(2.0,l/1.5));
    return 0;
}
