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

const ll mod = 998244353LL;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<vector<ll>> dp0(n), dp1(n);
    function<void(int, int)> dfs = [&](int vi, int pi) {
        int sz = 1;
        dp0[vi].assign(sz+1, 0);
        dp1[vi].assign(sz+1, 0);
        dp0[vi][0] = 1;
        dp1[vi][1] = 1;
        for (const int& ti : g[vi]) if (ti != pi) {
            dfs(ti, vi);
            int tlen = dp0[ti].size(), nsz = sz + tlen - 1;
            vector<ll> ndp0(nsz+1), ndp1(nsz+1);
            rep(i, tlen) rep(j, sz+1) {
                if (j+i-1 > nsz) break;
                if (j+i <= nsz) {
                    ndp0[j+i] = (ndp0[j+i] + dp0[vi][j] * dp0[ti][i]) % mod;
                    ndp0[j+i] = (ndp0[j+i] + dp0[vi][j] * dp1[ti][i]) % mod;
                    ndp1[j+i] = (ndp1[j+i] + dp1[vi][j] * dp0[ti][i]) % mod;
                }
                if (j+i-1 <= nsz && j+i-1 >= 0) ndp1[j+i-1] = (ndp1[j+i-1] + dp1[vi][j] * dp1[ti][i]) % mod;
            }
            swap(ndp0, dp0[vi]);
            swap(ndp1, dp1[vi]);
            swap(nsz, sz);
        }
    };
    dfs(0, -1);
    rep3(i, 1, n+1) cout << ((dp0[0][i]+dp1[0][i]) % mod) << endl;
    return 0;
}
