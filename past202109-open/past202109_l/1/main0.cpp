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

const ll LINF = (ll)(1e18);

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> s(n+1);
    rep(i, n) s[i+1] = s[i] + a[i];
    sort(all(s));
    ll lv = -1, rv = LINF;
    while (rv-lv > 1) {
        ll cv = rv - (rv-lv) / 2, cnt = (n+1) * (ll)(n+1) - (n+1);
        rep(i, n+1) {
            cnt -= lower_bound(all(s), s[i]-cv) - s.begin();
            cnt -= s.end() - upper_bound(all(s), s[i]+cv);
        }
        if (cnt/2 >= k) rv = cv;
        else lv = cv;
    }
    cout << rv << endl;
    return 0;
}
