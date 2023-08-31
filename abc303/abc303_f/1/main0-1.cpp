// 学習1回目,自力TLE

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using l3 = __int128_t;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll LINF = (ll)(1.5e18);

int main() {
    int n;
    ll h;
    cin >> n >> h;
    vector<int> t(n+1), d(n+1);
    rep(i, n) cin >> t[i] >> d[i];
    vector<pair<int, int>> td(n+1);
    rep(i, n) td[i] = { t[i], d[i] };
    td[n] = { 0, 0 };
    sort(all(td));
    rep(i, n+1) {
        t[i] = td[i].first;
        d[i] = td[i].second;
    }
    ll lv = 0, rv = h;
    while (rv-lv > 1) {
        ll cv = rv - (rv-lv) / 2, mval = 0;
        l3 sum = 0;
        multiset<int> dst;
        rep(i, n+1) dst.insert(d[i]);
        rep3(i, 1, n+1) {
            mval = max(mval, t[i-1]*(ll)d[i-1]);
            dst.erase(dst.find(d[i-1]));
            if (t[i-1] >= cv) break;
            int dv = *dst.rbegin();
            ll tri = min((ll)t[i], cv), tli = t[i-1], li = tli, ri = tri + 1;
            while (ri-li > 1) {
                ll ci = li + (ri-li) / 2;
                if (mval <= dv*ci) ri = ci;
                else li = ci;
            }
            sum += (ri - tli - 1) * mval + (ri+tri) * (l3)(tri+1-ri) / 2 * dv;
        }
        if (cv > t[n]) {
            mval = max(mval, t[n]*(ll)*dst.rbegin());
            sum += (l3)(cv - t[n]) * mval;
        }
        if (sum >= h) rv = cv;
        else lv = cv;
    }
    cout << rv << endl;
    return 0;
}
