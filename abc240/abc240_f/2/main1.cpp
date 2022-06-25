// 復習2回目,解説AC

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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), y(n);
        rep(i, n) cin >> x[i] >> y[i];
        ll a = 0, b = 0, res = numeric_limits<ll>::min();
        rep(i, n) {
            auto f = [&](int id) -> ll { return a + b * id + (ll)x[i] * id * (id+1) / 2; };
            if (x[i] >= 0) res = max({ res, f(1), f(y[i]) });
            else {
                int li = 0, ri = y[i]+1;
                while (ri-li > 2) {
                    int cl = li + (ri-li) / 2, cr = cl + 1;
                    if (f(cl) <= f(cr)) li = cl;
                    else ri = cr;
                }
                res = max(res, f(li+1));
            }
            a = f(y[i]);
            b += (ll)x[i] * y[i];
        }
        cout << res << endl;
    }
    return 0;
}
