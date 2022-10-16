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

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
        c[i]--;
    }
    vector<vector<int>> g(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    vector<int> scnt(n), gcnt(n);
    vector<ll> res(n, (ll)n*(n-1)/2);
    auto dfs = [&](auto dfs, int vi=0, int pi=-1, int id=0) -> int {
        gcnt[vi]++;
        int pval = scnt[c[vi]];
        for (const int& ti : g[vi]) if (ti != pi) {
            int pre = id - scnt[c[vi]];
            id = dfs(dfs, ti, vi, id);
            int nxt = id - scnt[c[vi]];
            gcnt[vi] += gcnt[ti];
            res[c[vi]] -= (ll)(nxt-pre) * (nxt-pre-1) / 2;
        }
        scnt[c[vi]] = pval + gcnt[vi];
        return id + 1;
    };
    dfs(dfs);
    rep(i, n) res[i] -= (ll)(n-scnt[i]) * (n-scnt[i]-1) / 2;
    rep(i, n) res[c[i]]++;
    rep(i, n) cout << res[i] << endl;
    return 0;
}
