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

int n;
vector<vector<int>> g;
vector<vector<ll>> dp;
vector<char> c;

void dfs(int v=0, int p=-1) {
    ll val0 = 1, val2 = 1;
    for (int t : g[v]) if (t != p) {
        dfs(t, v);
        if (c[v] == 'a') val0 = val0 * (dp[t][0] + dp[t][2]) % mod;
        else val0 = val0 * (dp[t][1] + dp[t][2]) % mod;
        val2 = val2 * (dp[t][0] + dp[t][1] + dp[t][2] * 2) % mod;
    }
    if (c[v] == 'a') dp[v][0] = val0;
    else dp[v][1] = val0;
    dp[v][2] = (val2 - val0 + mod) % mod;
}

int main() {
    cin >> n;
    c = vector<char>(n);
    rep(i, n) cin >> c[i];
    g = vector<vector<int>>(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    dp = vector<vector<ll>>(n, vector<ll>(3));
    dfs();
    cout << dp[0][2] << endl;
    return 0;
}
