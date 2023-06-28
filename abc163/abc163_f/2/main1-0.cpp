// 学習2回目,解説AC(練習用)

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
    vector<int> szs(n);
    function<int(int,int)> dfs0 = [&](int vi, int pi) {
        szs[vi]++;
        for (const int& ti : g[vi]) if (ti != pi) szs[vi] += dfs0(ti, vi);
        return szs[vi];
    };
    dfs0(0, -1);
    vector<int> cnts(n);
    vector<ll> subs(n);
    function<void(int,int)> dfs1 = [&](int vi, int pi) {
        int start = cnts[c[vi]];
        for (const int& ti : g[vi]) if (ti != pi) {
            int pre = cnts[c[vi]];
            dfs1(ti, vi);
            int nxt = cnts[c[vi]], val = szs[ti] - (nxt - pre);
            subs[c[vi]] += (ll)val * (val+1) / 2;
        }
        cnts[c[vi]] = start + szs[vi];
    };
    dfs1(0, -1);
    rep(i, n) {
        int val = n - cnts[i];
        subs[i] += (ll)val * (val + 1) / 2;
    }
    vector<ll> res(n);
    rep(i, n) res[i] = (ll)n * (n+1) / 2 - subs[i];
    rep(i, n) cout << res[i] << endl;
    return 0;
}
