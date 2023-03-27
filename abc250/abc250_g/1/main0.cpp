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

pair<ll, int> op(pair<ll, int> a, pair<ll, int> b) { return min(a, b); }
pair<ll, int> e() { return { LINF, 0 }; }

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    priority_queue<pair<ll, int>> pq;
    rep(i, n) pq.emplace(p[i], -i);
    vector<bool> used(n);
    segtree<pair<ll, int>, op, e> st(n);
    rep(i, n) st.set(i, { p[i], -i });
    ll res = 0;
    while (!pq.empty()) {
        auto pi = pq.top(); pq.pop();
        ll rval = pi.first; int ri = -pi.second;
        if (used[ri]) continue;
        used[ri] = true;
        st.set(ri, { LINF, -ri });
        auto qi = st.prod(0, ri);
        ll lval = qi.first; int li = -qi.second;
        if (lval == LINF) continue;
        used[li] = true;
        st.set(li, { LINF, -li });
        res += max(0LL, rval-lval);
    }
    cout << res << endl;
    return 0;
}
