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

const ll mod = 998244353LL;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    int m = *max_element(all(a)) + (int)(ceil(log(n) / log(2)));
    vector<int> acnt(m+1);
    rep(i, n) acnt[a[i]]++;
    vector<ll> dp(2), ndp;
    dp[0] = 1;
    rep(i, m) {
        int k = dp.size() - 1, nk = (acnt[i] + k - 1) / 2 + 1;
        ndp.assign(nk+1, 0);
        rep(j, k) {
            int ri = (acnt[i] + j) / 2;
            ndp[0] = (ndp[0] + dp[j]) % mod;
            ndp[ri+1] = (ndp[ri+1] - dp[j] + mod) % mod;
        }
        rep(j, nk) ndp[j+1] = (ndp[j+1] + ndp[j]) % mod;
        swap(ndp, dp);
    }
    cout << dp[0] << endl;
    return 0;
}
