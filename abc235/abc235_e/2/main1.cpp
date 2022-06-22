// 学習2回目,解説AC1

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
    rep(i, m+q) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    vector<tuple<int, int, int, int>> elst(m+q);
    rep(i, m+q) elst[i] = { c[i], a[i], b[i], i };
    sort(all(elst));
    vector<bool> res(q);
    dsu ds(n);
    rep(i, m+q) {
        auto [ci, ai, bi, id] = elst[i];
        if (!ds.same(ai, bi)) {
            if (id >= m) res[id-m] = true;
            else ds.merge(ai, bi);
        }
    }
    rep(i, q) cout << (res[i] ? "Yes" : "No") << endl;
    return 0;
}
