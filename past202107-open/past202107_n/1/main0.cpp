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
pair<int, int> op(pair<int, int> ai, pair<int, int> bi) { return { ai.first+bi.first, ai.second+bi.second }; }
pair<int, int> e() { return { 0, 0 }; }
pair<int, int> mapping(bool f, pair<int, int> x) { return { f ? x.second-x.first : x.first, x.second }; }
bool composition(bool f, bool g) { return f ? !g : g; }
bool id() { return false; }

int main() {
    int q;
    cin >> q;
    vector<int> a(q), b(q), c(q), d(q);
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> xlst;
    rep(i, q) {
        xlst.push_back(a[i]);
        xlst.push_back(c[i]);
    }
    sort(all(xlst));
    xlst.erase(unique(all(xlst)), xlst.end());
    rep(i, q) {
        a[i] = lower_bound(all(xlst), a[i]) - xlst.begin();
        c[i] = lower_bound(all(xlst), c[i]) - xlst.begin();
    }
    vector<tuple<int, int, int>> tlst;
    rep(i, q) {
        tlst.emplace_back(b[i], a[i], c[i]);
        tlst.emplace_back(d[i], a[i], c[i]);
    }
    sort(all(tlst));
    int m = xlst.size(), tlen = tlst.size();
    lazy_segtree<pair<int, int>, op, e, bool, mapping, composition, id> lst(m);
    rep(i, m-1) lst.set(i, { 0, xlst[i+1]-xlst[i] });
    ll res = 0;
    rep(i, tlen-1) {
        int yval = get<0>(tlst[i+1]) - get<0>(tlst[i]);
        lst.apply(get<1>(tlst[i]), get<2>(tlst[i]), true);
        res += yval * (ll)lst.all_prod().first;
    }
    cout << res << endl;
    return 0;
}
