// 自力AC

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

int main(){
    string x;
    ll m;
    cin >> x >> m;
    if ((int)(x.length()) == 1) {
        if ((ll)(x.front()-'0') <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int mval = 0;
    rep(i, x.length()) mval = max(mval, (int)(x[i]-'0'));
    if ((int)(x.length()) == 2) {
        ll sub = (m - (x[1]-'0')) / (ll)(x[0]-'0');
        cout << max(0LL, sub-mval) << endl;
        return 0;
    }
    if ((int)(x.length()) == 3) {
        ll tval = (ll)(sqrt((double)m/(ll)(x.front()-'0'))) + 1;
        while (1) {
            ll nval = 0;
            rep(i, x.length()) {
                nval *= tval;
                nval += (ll)(x[i]-'0');
            }
            if (nval <= m) break;
            --tval;
        }
        cout << max(0LL, tval-mval) << endl;
        return 0;
    }
    int cnt = 0;
    while (1) {
        ++mval;
        ll nval = 0;
        rep(i, x.length()) {
            nval *= mval;
            nval += (int)(x[i]-'0');
            if (nval > m) break;
        }
        if (nval <= m) ++cnt;
        else break;
    }
    cout << cnt << endl;
    return 0;
}
