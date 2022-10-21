// 学習1回目,解説AC

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
    int n;
    cin >> n;
    vector<int> x(n), c(n);
    rep(i, n) {
        cin >> x[i];
        x[i]--;
    }
    rep(i, n) cin >> c[i];
    dsu d(n);
    ll res = 0;
    rep(i, n) {
        if (!d.same(i, x[i])) d.merge(i, x[i]);
        else {
            int mval = c[i], id = x[i];
            while (id != i) {
                mval = min(mval, c[id]);
                id = x[id];
            }
            res += mval;
        }
    }
    cout << res << endl;
    return 0;
}
