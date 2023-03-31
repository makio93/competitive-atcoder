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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

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
    vector dp0(n, -LINF), dp1(n, -LINF);
    auto dfs = [&](auto dfs, int vi=0, int pi=-1) -> void {
        vector<ll> slst;
        ll ssum = 0;
        for (const auto& tpi : g[vi]) if (tpi.first != pi) {
            int ti = tpi.first;
            dfs(dfs, ti, vi);
            ssum += dp1[ti];
            if (dp0[ti] > -LINF) slst.push_back((dp0[ti]+tpi.second)-dp1[ti]);
        }
        sort(all(slst), greater<ll>());
        rep(i, d[vi]+1) {
            if (i == d[vi]-1) dp0[vi] = ssum;
            if (i == d[vi]) dp1[vi] = ssum;
            if (i<(int)(slst.size()) && slst[i]>=0) ssum += slst[i];
        }
        chmax(dp1[vi], dp0[vi]);
        return;
    };
    dfs(dfs);
    cout << dp1[0] << endl;
    return 0;
}
