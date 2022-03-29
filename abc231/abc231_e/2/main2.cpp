// 復習2,解説1

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
    map<pair<int, ll>, ll> memo;
    auto f = [&](auto f, int d, ll xi) -> ll {
        if (memo.find({d, xi}) != memo.end()) return memo[{d, xi}];
        if (d == n-1) return memo[{d, xi}] = xi / a[d];
        else {
            ll ri = xi % a[d+1];
            ll res = ri / a[d] + f(f, d+1, xi/a[d+1]*a[d+1]);
            if (ri > 0) res = min(res, (a[d+1]-ri)/a[d]+f(f,d+1,xi/a[d+1]*a[d+1]+a[d+1]));
            return memo[{d, xi}] = res;
        }
    };
    cout << f(f, 0, x) << endl;
    return 0;
}
