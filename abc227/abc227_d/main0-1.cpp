// 練習

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll l = 1, r = (ll)(1e18);
    while (r-l > 1) {
        ll c = l + (r-l) / 2;
        ll sum = 0;
        rep(i, n) sum += min(c, a[i]);
        if (sum/k >= c) l = c;
        else r = c;
    }
    cout << l << endl;
    return 0;
}
