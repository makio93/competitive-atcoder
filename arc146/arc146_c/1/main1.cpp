// 学習1回目,解説AC

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
using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<mint> dp(n+2);
    dp[0] = 1, dp[1] = mint(2).pow(n);
    rep3(i, 1, n+1) dp[i+1] = dp[i] * (mint(2).pow(n) - mint(2).pow(i-1)) / (i+1);
    mint res = 0;
    rep(i, n+2) res += dp[i];
    cout << res.val() << endl;
    return 0;
}
