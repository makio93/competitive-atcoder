// 学習3回目,解説AC2

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

const int INF = (int)(1e9);

int main() {
    double p;
    cin >> p;
    auto fp = [&](double x) -> double {
        return 1.0 - p / 1.5 * log(2.0) / pow(2.0, x/1.5);
    };
    if (fp(0.0) > 0.0) {
        printf("%.10f\n", p);
        return 0;
    }
    double lx = 0.0, rx = p;
    while (rx-lx > 1e-9) {
        double cx = lx + (rx-lx) / 2.0;
        if (fp(cx) >= 0.0) rx = cx;
        else lx = cx;
    }
    double res = lx + p / pow(2.0, lx/1.5);
    printf("%.10f\n", res);
    return 0;
}
