// 復習1回目,自力AC

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
    int n, k;
    cin >> n >> k;
    vector<int> p(n), q(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) {
        cin >> q[i];
        q[i]--;
    }
    vector<int> pid(n);
    iota(all(pid), 0);
    sort(all(pid), [&](int li, int ri) -> bool { return p[li] < p[ri]; });
    vector<vector<ll>> dp(k+1, vector<ll>(n+1));
    dp[0][n] = 1;
    rep(i1, n) {
        vector<vector<ll>> ndp(k+1, vector<ll>(n+1));
        rep(i, k+1) rep(j, n+1) {
            if (i+1<=k && q[pid[i1]]<j) ndp[i+1][j] = (ndp[i+1][j] + dp[i][j]) % mod;
            ndp[i][min(j, q[pid[i1]])] = (ndp[i][min(j, q[pid[i1]])] + dp[i][j]) % mod;
        }
        swap(ndp, dp);
    }
    ll res = 0;
    rep(i, n+1) res = (res + dp[k][i]) % mod;
    cout << res << endl;
    return 0;
}
