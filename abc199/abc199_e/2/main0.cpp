// 学習2回目,自力AC

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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m), z(m);
    rep(i, m) cin >> x[i] >> y[i] >> z[i];
    vector<vector<pair<int, int>>> mlst(n+1);
    rep(i, m) mlst[x[i]].emplace_back(y[i], z[i]);
    vector<bool> status(1<<n, true);
    rep(i, 1<<n) {
        int bi = __builtin_popcount(i);
        for (const auto& pi : mlst[bi]) if (__builtin_popcount(i&((1<<pi.first)-1)) > pi.second) {
            status[i] = false;
            break;
        }
    }
    vector<ll> dp(1<<n);
    dp[0] = 1;
    rep(i, (1<<n)-1) rep(j, n) if (!(i&(1<<j))) {
        int ti = i|(1<<j);
        if (!status[ti]) continue;
        dp[ti] += dp[i];
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}
