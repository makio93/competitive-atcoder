// 学習1回目,自力AC

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
    int n;
    ll m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    int li = 0, ri = INF;
    while (ri-li > 1) {
        int ci = li + (ri-li) / 2;
        ll cnt = 0;
        rep(i, n) cnt += n - (upper_bound(all(a), ci-a[i]) - a.begin());
        if (cnt > m) li = ci;
        else ri = ci;
    }
    ll res = 0, scnt = 0;
    vector<ll> sums(n+1);
    repr(i, n) sums[i] = sums[i+1] + a[i];
    rep(i, n) {
        int id = upper_bound(all(a), ri-a[i]) - a.begin();
        scnt += n - id;
        res += sums[id] + a[i] * (ll)(n-id);
    }
    res += (m - scnt) * ri;
    cout << res << endl;
    return 0;
}
