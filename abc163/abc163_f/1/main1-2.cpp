// 学習1回目,解説AC2

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

ll sigma(ll val) { return val * (val + 1) / 2; }

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
    vector<int> in(n), out(n);
    int k = 0;
    function<void(int,int)> dfs = [&](int vi, int pi) {
        in[vi] = k++;
        for (const int& ti : g[vi]) if (ti != pi) dfs(ti, vi);
        out[vi] = k;
    };
    dfs(0, -1);
    vector<vector<int>> clst(n);
    rep(i, n) clst[c[i]].push_back(i);
    fenwick_tree<int> ft(n);
    rep(i, n) ft.add(i, 1);
    rep(i, n) {
        ll res = sigma(n);
        vector<pair<int, int>> hist;
        sort(all(clst[i]), [&](int ai, int bi) { return in[ai] > in[bi]; });
        for (const int& vi : clst[i]) {
            int sval = 1;
            for (const int& ti : g[vi]) if (in[ti] > in[vi]) {
                int tval = ft.sum(in[ti], out[ti]);
                res -= sigma(tval);
                sval += tval;
            }
            ft.add(in[vi], -sval);
            hist.emplace_back(in[vi], sval);
        }
        res -= sigma(ft.sum(0, n));
        cout << res << endl;
        for (const auto& pi : hist) ft.add(pi.first, pi.second);
    }
    return 0;
}
