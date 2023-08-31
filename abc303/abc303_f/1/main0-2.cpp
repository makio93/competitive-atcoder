// 学習1回目,自力AC(ヒント有)

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
    ll res = -1, mval = 0, sum = 0;
    multiset<int> dst;
    rep(i, n+1) dst.insert(d[i]);
    rep3(i, 1, n+1) {
        mval = max(mval, t[i-1]*(ll)d[i-1]);
        dst.erase(dst.find(d[i-1]));
        int dv = *dst.rbegin();
        ll tri = t[i], tli = t[i-1], li = tli, ri = tri + 1;
        while (ri-li > 1) {
            ll ci = li + (ri-li) / 2;
            if (mval <= dv*ci) ri = ci;
            else li = ci;
        }
        l3 val1 = (ri - tli - 1) * mval, val2 = (ri+tri) * (l3)(tri+1-ri) / 2 * dv;
        if (sum+val1+val2 < h) sum += val1 + val2;
        else {
            if (sum+val1 >= h) res = t[i-1] + (h - sum + mval - 1) / mval;
            else {
                sum += val1;
                int l2 = ri-1, r2 = t[i];
                while (r2-l2 > 1) {
                    int c2 = r2 - (r2-l2) / 2;
                    if (sum+(ri+c2)*(l3)(c2-ri+1)/2*dv >= h) r2 = c2;
                    else l2 = c2;
                }
                res = r2;
            }
            break;
        }
    }
    if (res == -1) {
        mval = max(mval, t[n]*(ll)*dst.rbegin());
        res = t[n] + (h - sum + mval - 1) / mval;
    }
    cout << res << endl;
    return 0;
}
