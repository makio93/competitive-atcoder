// 学習2回目,自力AC1

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

const double DINF = 1e18;

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> w(n), x(n), v(n);
    rep(i, n) cin >> w[i] >> x[i] >> v[i];
    int res = 0;
    rep(i, n) {
        vector<pair<double, int>> wlst;
        wlst.emplace_back(-DINF, -w[i]);
        wlst.emplace_back(0.0, 0);
        rep(j, n) if (i != j) {
            if (v[j] == v[i]) { if (x[j]>=x[i] && x[j]<=x[i]+a) wlst.emplace_back(-DINF, -w[j]); }
            else {
                double lv = (x[i]-x[j]) / (double)(v[j]-v[i]), rv = (x[i]+a-x[j]) / (double)(v[j]-v[i]);
                if (lv > rv) swap(lv, rv);
                wlst.emplace_back(lv, -w[j]);
                wlst.emplace_back(rv, w[j]);
            }
        }
        sort(all(wlst));
        int wval = 0;
        for (const auto& [ti, wi] : wlst) {
            wval += wi;
            if (ti >= 0.0) res = max(res, -wval);
        }
    }
    cout << res << endl;
    return 0;
}
