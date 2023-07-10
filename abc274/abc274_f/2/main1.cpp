// 学習2回目,解説AC

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

const int INF = (ll)(1e9);

struct fraction {
    ll num, den;
    fraction(ll num=0, ll den=1) {
        this->num = num, this->den = den;
        if (this->den < 0) this->num *= -1, this->den *= -1;
    }
    bool operator<(const fraction& other) const {
        return num * other.den < other.num * den;
    }
    bool operator<=(const fraction& other) const {
        return num * other.den <= other.num * den;
    }
};

int main() {
    int n, a;
    cin >> n >> a;
    vector<int> w(n), x(n), v(n);
    rep(i, n) cin >> w[i] >> x[i] >> v[i];
    int res = 0;
    rep(i, n) {
        vector<tuple<fraction, bool, int>> wlst;
        wlst.emplace_back(fraction(-INF, 1), false, w[i]);
        wlst.emplace_back(fraction(0, 1), false, 0);
        rep(j, n) if (i != j) {
            if (v[j] == v[i]) { if (x[j]>=x[i] && x[j]<=x[i]+a) wlst.emplace_back(fraction(-INF, 1), false, w[j]); }
            else {
                fraction lv = fraction(x[i]-x[j], v[j]-v[i]), rv = fraction(x[i]+a-x[j], v[j]-v[i]);
                if (rv < lv) swap(lv, rv);
                wlst.emplace_back(lv, false, w[j]);
                wlst.emplace_back(rv, true, -w[j]);
            }
        }
        sort(all(wlst));
        int wval = 0;
        for (const auto& [ti, bi, wi] : wlst) {
            wval += wi;
            if (fraction(0, 1) <= ti) res = max(res, wval);
        }
    }
    cout << res << endl;
    return 0;
}
