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

const int INF = (int)(1.5e9);

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(m+q), b(m+q), c(m+q);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    rep(i, q) {
        cin >> a[m+i] >> b[m+i] >> c[m+i];
        a[m+i]--; b[m+i]--;
    }
    vector<int> ord(m+q);
    iota(all(ord), 0);
    sort(all(ord), [&](int li, int ri) -> bool { return c[li] < c[ri]; });
    vector<bool> res(q);
    dsu ds(n);
    rep(i, m+q) if (!ds.same(a[ord[i]], b[ord[i]])) {
        if (ord[i] >= m) res[ord[i]-m] = true;
        else ds.merge(a[ord[i]], b[ord[i]]);
    }
    rep(i, q) cout << (res[i] ? "Yes" : "No") << endl;
    return 0;
}
