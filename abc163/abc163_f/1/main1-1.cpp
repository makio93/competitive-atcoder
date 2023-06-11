// 学習1回目,解説AC1

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

const int INF = (int)(1e9);

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
    vector<ll> res(n, (ll)n*(n-1)/2);
    vector<int> ccnt(n), sub(n);
    int scnt = 0;
    function<void(int,int)> dfs = [&](int vi, int pi) {
        sub[vi] = 1;
        int inval = ccnt[c[vi]];
        for (const int& ti : g[vi]) if (ti != pi) {
            int pre = scnt - ccnt[c[vi]];
            dfs(ti, vi);
            sub[vi] += sub[ti];
            int nxt = scnt - ccnt[c[vi]];
            res[c[vi]] -= (nxt-pre) * (ll)(nxt-pre-1) / 2;
        }
        ccnt[c[vi]] = inval + sub[vi];
        ++scnt;
    };
    dfs(0, -1);
    rep(i, n) {
        int pre = 0, nxt = n - ccnt[i];
        res[i] -= (nxt-pre) * (ll)(nxt-pre-1) / 2;
    }
    rep(i, n) res[c[i]]++;
    rep(i, n) cout << res[i] << endl;
    return 0;
}
