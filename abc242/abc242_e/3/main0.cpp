// 学習3回目,自力AC

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

const ll mod = 998244353LL;

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        string s;
        cin >> n >> s;
        ll res = 0, pow26 = 1;
        repr(i, (n+1)/2) {
            res = (res + (s[i] - 'A') * pow26) % mod;
            pow26 = pow26 * 26 % mod;
        }
        string t = s;
        rep(i, n/2) t[n-1-i] = t[i];
        if (t <= s) res = (res + 1) % mod;
        cout << res << endl;
    }
    return 0;
}
