// 学習3回目,自力AC

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
    auto f = [&](double x) -> double {
        return x + p / pow(2.0, x/1.5);
    };
    double lx = 0.0, rx = p;
    while (rx-lx > 1e-9) {
        double clx = lx + (rx-lx) / 3.0, crx = rx - (rx-lx) / 3.0;
        double clf = f(clx), crf = f(crx);
        if (clf > f(lx)) rx = crx;
        else if (crf > f(rx)) lx = clx;
        else if (clf <= crf) rx = crx;
        else lx = clx;
    }
    double res = f(lx);
    printf("%.10f\n", res);
    return 0;
}
