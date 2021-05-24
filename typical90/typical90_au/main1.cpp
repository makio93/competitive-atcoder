#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const ll mod = (ll)(1e9) + 7;
const string tar = "RGB";

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> sval(n), tval(n);
    rep(i, n) rep(j, 3) if (tar[j] == s[i]) sval[i] = j;
    rep(i, n) rep(j, 3) if (tar[j] == t[i]) tval[i] = j;
    ll res = 0;
    rep(i1, 3) {
        vector<int> sval2(n);
        rep(i, n) sval2[i] = (i1 - tval[i] + 3) % 3;
        ll hval = 0, hval2 = 0, pval = 1;
        rep(i, n) {
            hval = (hval * 3 + sval[i]) % mod;
            hval2 = (hval2 + sval2[n-1-i] * pval) % mod;
            pval = pval * 3 % mod;
            if (hval == hval2) ++res;
        }
        hval = 0; hval2 = 0; pval = 1;
        rep(i, n-1) {
            hval2 = (hval2 * 3 + sval2[i]) % mod;
            hval = (hval + sval[n-1-i] * pval) % mod;
            pval = pval * 3 % mod;
            if (hval == hval2) ++res;
        }
    }
    cout << res << endl;
    return 0;
}
