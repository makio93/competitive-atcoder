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

const int INF = (int)(2e9);

int main() {
    int n;
    cin >> n;
    vector<int> x(n), c(n);
    rep(i, n) {
        cin >> x[i];
        x[i]--;
    }
    rep(i, n) cin >> c[i];
    dsu uf(n);
    ll res = 0;
    rep(i, n) {
        if (!uf.same(i, x[i])) {
            uf.merge(i, x[i]);
            continue;
        }
        int val = c[i], vi = x[i];
        while (vi != i) {
            val = min(val, c[vi]);
            vi = x[vi];
        }
        res += val;
    }
    cout << res << endl;
    return 0;
}
