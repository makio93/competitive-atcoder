// 学習1回目,解説AC1

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
    vector<pair<double, pair<int, int>>> dlst;
    rep(i, n) dlst.emplace_back((100.0-y[i])/2.0, make_pair(n, i));
    rep(i, n) dlst.emplace_back((y[i]+100.0)/2.0, make_pair(n+1, i));
    auto dist = [&x,&y](int ai, int bi) -> double {
        return sqrt((x[ai]-x[bi])*(x[ai]-x[bi])+(y[ai]-y[bi])*(y[ai]-y[bi]));
    };
    rep(i, n) rep3(j, i+1, n) dlst.emplace_back(dist(i,j)/2.0, make_pair(i, j));
    sort(all(dlst));
    dsu d(n+2);
    double res = 0.0;
    for (const auto& di : dlst) {
        res = di.first;
        auto [ai, bi] = di.second;
        d.merge(ai, bi);
        if (d.same(n, n+1)) break;
    }
    cout << fixed << setprecision(18) << res << endl;
    return 0;
}
