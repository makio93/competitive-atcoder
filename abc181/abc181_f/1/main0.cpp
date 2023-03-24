// 学習1回目,自力AC

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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    auto calc = [&x,&y](int ai, int bi) -> double {
        return sqrt((x[ai]-x[bi])*(x[ai]-x[bi])+(y[ai]-y[bi])*(y[ai]-y[bi]));
    };
    double li = 0.0, ri = 200.0;
    dsu d;
    while (ri-li > 2e-4) {
        double ci = li + (ri-li) / 2.0;
        d = dsu(n+2);
        rep(i, n) {
            if (100-y[i] < ci) d.merge(n, i);
            if (y[i]+100 < ci) d.merge(n+1, i);
        }
        rep(i, n) rep3(j, i+1, n) if (calc(i, j) < ci) d.merge(i, j);
        if (d.same(n, n+1)) ri = ci;
        else li = ci;
    }
    double res = li / 2.0;
    cout << fixed << setprecision(20) << res << endl;
    return 0;
}
