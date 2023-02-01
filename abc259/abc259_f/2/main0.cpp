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

const ll LINF = (ll)(1e15);

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    vector<vector<pair<int, int>>> g(n);
    rep(i, n-1) {
        int ui, vi, wi;
        cin >> ui >> vi >> wi;
        --ui; --vi;
        g[ui].emplace_back(vi, wi);
        g[vi].emplace_back(ui, wi);
    }
    vector<ll> dp0(n, -LINF), dp1(n);
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        for (const auto& tpi : g[vi]) if (tpi.first != pi) dfs(dfs, tpi.first, vi);
        ll sum0 = 0;
        for (const auto& tpi : g[vi]) if (tpi.first != pi) sum0 += dp1[tpi.first];
        if (d[vi] == 0) dp1[vi] = sum0;
        else {
            vector<ll> slst;
            for (const auto& tpi : g[vi]) if (tpi.first != pi) slst.push_back((dp0[tpi.first]+tpi.second)-dp1[tpi.first]);
            sort(slst.rbegin(), slst.rend());
            ll sub0 = 0, sub1 = 0;
            int slen = slst.size();
            rep(i, slen) {
                if (slst[i]<0 || i>=d[vi]) break;
                if (i < d[vi]-1) sub0 += slst[i];
                if (i < d[vi]) sub1 += slst[i];
            }
            dp0[vi] = sum0 + sub0;
            dp1[vi] = sum0 + sub1;
        }
    };
    dfs(dfs);
    cout << dp1[0] << endl;
    return 0;
}
