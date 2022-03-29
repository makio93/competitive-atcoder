// 復習2,解説1,2回目

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

ll ceil(ll a, ll b) { return a / b + !!(a % b); }

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    unordered_map<ll, ll> memo;
    auto f = [&](auto f, int d, ll xi) -> ll {
        if (memo.find(xi) != memo.end()) return memo[xi];
        if (d == n-1) return memo[xi] = xi / a[d];
        if (xi == 0) return memo[xi] = 0;
        ll ri = xi % a[d+1] / a[d], res = ri + f(f, d+1, xi/a[d+1]*a[d+1]);
        if (ri) res = min(res, a[d+1]/a[d]-ri + f(f, d+1, ceil(xi,a[d+1])*a[d+1]));
        return memo[xi] = res;
    };
    cout << f(f, 0, x) << endl;
    return 0;
}
