// 解説AC

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

int main(){
    string x;
    ll m;
    cin >> x >> m;
    if ((int)(x.length()) == 1) {
        if ((ll)(x[0]-'0') <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int mval = 0;
    rep(i, (int)(x.length())) mval = max(mval, (int)(x[i]-'0'));
    if ((ll)(mval+1) > m) {
        cout << 0 << endl;
        return 0;
    }
    ll l = 1, r = m+1;
    while (r-l > 1) {
        ll c = (l+r) / 2, tval = 0;
        rep(i, x.length()) {
            if (tval>m/c) {
                tval = m + 1;
                break;
            }
            tval *= c;
            tval += (ll)(x[i]-'0');
            if (tval > m) break;
        }
        if (tval <= m) l = c;
        else r = c;
    }
    cout << max(0LL, l-(ll)mval) << endl;
    return 0;
}
