// 学習1回目,自力WA

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

const ll LINF = (ll)(1e18);
ll op(ll ai, ll bi) { return max(ai, bi); }
ll e() { return -LINF; }
ll mapping(ll f, ll x) { return x + f; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0LL; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m), a(m);
    rep(i, m) {
        cin >> l[i] >> r[i] >> a[i];
        l[i]--; r[i]--;
    }
    vector<vector<pair<int, int>>> rtol(n);
    rep(i, m) rtol[r[i]].emplace_back(l[i], a[i]);
    lazy_segtree<ll, op, e, ll, mapping, composition, id> lst(n);
    lst.set(0, 0LL);
    rep(i, n) {
        ll asum = 0;
        for (const auto& pi : rtol[i]) asum += pi.second;
        lst.set(i, (lst.prod(0, i) == e() ? 0LL : lst.prod(0, i)) + asum);
        for (const auto& pi : rtol[i]) lst.apply(pi.first, i, (ll)pi.second);
    }
    cout << max(0LL, lst.prod(0, n)) << endl;
    return 0;
}
