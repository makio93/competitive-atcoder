// 学習2回目,自力AC

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

pair<int, int> op(pair<int, int> a, pair<int, int> b) { return make_pair(a.first+b.first, a.second+b.second); }
pair<int, int> e() { return make_pair(0, 0); }
pair<int, int> mapping(bool f, pair<int, int> x) { return f ? make_pair(x.second-x.first, x.second) : x; }
bool composition(bool f, bool g) { return f ? !g : g; }
bool id() { return false; }

int main() {
    int q;
    cin >> q;
    vector<int> a(q), b(q), c(q), d(q);
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    function<int(vector<int>&, vector<int>&, vector<int>&)> compress = [&](vector<int>& target, vector<int>& source1, vector<int>& source2) {
        rep(i, q) {
            target.push_back(source1[i]);
            target.push_back(source2[i]);
        }
        sort(all(target));
        target.erase(unique(all(target)), target.end());
        return (int)(target.size());
    };
    vector<int> xlst, ylst;
    int xlen = compress(xlst, a, c), ylen = compress(ylst, b, d);
    function<int(vector<int>&, int)> vtoid = [&](vector<int>& vlst, int val) {
        return lower_bound(all(vlst), val) - vlst.begin();
    };
    vector<vector<pair<int, int>>> ytox(ylen);
    rep(i, q) {
        ytox[vtoid(ylst, b[i])].emplace_back(vtoid(xlst, a[i]), vtoid(xlst, c[i]));
        ytox[vtoid(ylst, d[i])].emplace_back(vtoid(xlst, a[i]), vtoid(xlst, c[i]));
    }
    lazy_segtree<pair<int, int>, op, e, bool, mapping, composition, id> lst(xlen);
    rep(i, xlen-1) lst.set(i, { 0, xlst[i+1]-xlst[i] });
    ll res = 0;
    rep(i, ylen-1) {
        for (const auto& pi : ytox[i]) lst.apply(pi.first, pi.second, true);
        res += lst.prod(0, xlen).first * (ll)(ylst[i+1] - ylst[i]);
    }
    cout << res << endl;
    return 0;
}
