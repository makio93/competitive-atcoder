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

// 解説AC（ACLを用いて）

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> c(m), l(m), r(m);
    rep(i, m) cin >> c[i] >> l[i] >> r[i];
    vector<tuple<int, int, int>> clr(m);
    rep(i, m) clr[i] = { c[i], l[i]-1, r[i] };
    sort(all(clr));
    dsu d(n+1);
    ll res = 0; int cnt = 0;
    rep(i, m) {
        int ci = get<0>(clr[i]), ui = get<1>(clr[i]), vi = get<2>(clr[i]);
        if (!d.same(ui, vi)) {
            d.merge(ui, vi);
            res += ci;
            ++cnt;
        }
    }
    if (cnt < n) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
