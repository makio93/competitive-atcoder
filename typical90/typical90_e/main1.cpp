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

// 解説を見てから実装、AC

using mint = modint1000000007;

ll modpow(ll a, ll b, ll m) {
    ll p = 1, q = a;
    rep(i, 63) {
        if (b & (1LL<<i)) p = p * q % m;
        q = q * q % m;
    }
    return p;
}

int main() {
    ll N;
    int B, K;
    cin >> N >> B >> K;
    vector<int> C(K);
    rep(i, K) cin >> C[i];
    int imx = 0;
    while (N >= (1LL<<imx)) ++imx;
    vector<vector<mint>> dp(imx+1, vector<mint>(B));
    vector<ll> pow10(imx+1);
    rep(i, imx+1) pow10[i] = modpow(10, (1LL<<i), B);
    rep(i, K) dp[0][C[i]%B]++;
    rep(i, imx) {
        rep(j, B) rep(k, B) {
            ll nxj = (j * pow10[i] + k) % B;
            dp[i+1][(int)(nxj)] += dp[i][j] * dp[i][k];
        }
    }
    vector<vector<mint>> res(imx+1, vector<mint>(B));
    res[0][0] = 1;
    rep(i, imx) {
        if ((1LL<<i) & N) {
            rep(j, B) rep(k, B) {
                ll nxj = (j * pow10[i] + k) % B;
                res[i+1][(int)(nxj)] += res[i][j] * dp[i][k];
            }
        }
        else rep(j, B) res[i+1][j] += res[i][j];
    }
    cout << res[imx][0].val() << endl;
    return 0;
}
