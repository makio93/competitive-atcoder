// 学習2回目,解説AC4

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

int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(all(a), greater<ll>());
    sort(all(b), greater<ll>());
    sort(all(c), greater<ll>());
    ll lv = 1, rv = a[0] + b[0] + c[0] + 1;
    while (rv-lv > 1) {
        ll cv = lv + (rv - lv) / 2;
        int cnt = 0;
        auto is_ok = [&]() -> bool {
            rep(i1, x) rep(i2, y) rep(i3, z) {
                if (a[i1]+b[i2]+c[i3] < cv) break;
                ++cnt;
                if (cnt >= k) return true;
            }
            return false;
        };
        if (is_ok()) lv = cv;
        else rv = cv;
    }
    vector<ll> res;
    rep(i1, x) rep(i2, y) rep(i3, z) {
        if (a[i1]+b[i2]+c[i3] < lv+1) break;
        res.push_back(a[i1]+b[i2]+c[i3]);
    }
    while ((int)(res.size()) < k) res.push_back(lv);
    sort(all(res), greater<ll>());
    rep(i, k) cout << res[i] << endl;
    return 0;
}
