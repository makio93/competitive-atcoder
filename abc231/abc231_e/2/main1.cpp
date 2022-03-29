// 復習2,動画1

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

const ll INF = (ll)(2e18);

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> dp(2);
    dp[1] = INF;
    rep(i, n-1) {
        ll di = a[i+1] / a[i], xi = x % di;
        vector<ll> ndp(2, INF);
        rep(j, 2) rep(nj, 2) ndp[nj] = min(ndp[nj], dp[j]+abs(j-di*nj+xi));
        swap(ndp, dp);
        x /= di;
    }
    ll res = INF;
    rep(i, 2) res = min(res, dp[i]+abs(x+i));
    cout << res << endl;
    return 0;
}
