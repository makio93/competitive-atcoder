// 学習2回目,解説AC2

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
    vector<ll> res;
    rep(i, x) rep(j, y) rep(l, z) {
        if ((i+1)*(j+1)*(l+1) > k) break;
        res.push_back(a[i]+b[j]+c[l]);
    }
    sort(all(res), greater<ll>());
    rep(i, k) cout << res[i] << endl;
    return 0;
}
