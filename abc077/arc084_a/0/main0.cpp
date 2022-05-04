// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(all(a)); sort(all(b)); sort(all(c));
    vector<ll> bc(n);
    repr(i, n) {
        auto itr = lower_bound(all(c), b[i]+1);
        bc[i] = c.end() - itr;
        if (i < n-1) bc[i] += bc[i+1];
    }
    ll ans = 0;
    rep(i, n) {
        auto itr = lower_bound(all(b), a[i]+1);
        ans += bc[itr-b.begin()];
    }
    cout << ans << endl;
    return 0;
}
