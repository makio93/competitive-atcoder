// 復習1,自力AC1

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

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m), b(m), c(m), u(q), v(q), w(q);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    rep(i, q) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
    }
    vector<pair<int, int>> elst;
    rep(i, m) elst.emplace_back(c[i], i);
    rep(i, q) elst.emplace_back(w[i], m+i);
    sort(all(elst));
    dsu d(n);
    vector<bool> ans(q);
    rep(i, m+q) {
        if (elst[i].second < m) {
            if (!d.same(a[elst[i].second], b[elst[i].second])) d.merge(a[elst[i].second], b[elst[i].second]);
        }
        else ans[elst[i].second-m] = !d.same(u[elst[i].second-m], v[elst[i].second-m]);
    }
    rep(i, q) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
