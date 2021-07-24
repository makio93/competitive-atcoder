#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

ll gcd(ll a, ll b) { return (b ? gcd(b, a%b) : a); }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), c(m);
    rep(i, m) cin >> a[i] >> c[i];
    vector<pair<int, int>> ca;
    ca.emplace_back(0, n);
    rep(i, m) ca.emplace_back(c[i], a[i]);
    sort(all(ca));
    ll g = ca.front().second, res = 0, rest = n-1;
    rep3(i, 1, m+1) {
        ll g2 = gcd(g, ca[i].second);
        res += (ll)ca[i].first * min(rest, g-g2);
        rest -= min(rest, g-g2);
        g = g2;
        if (rest == 0) break;
    }
    if (rest == 0) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}
