// 学習1回目,自力AC

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

const int INF = (int)(1.5e9);

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> s(n), t(n), x(n), d(q);
    rep(i, n) cin >> s[i] >> t[i] >> x[i];
    rep(i, q) cin >> d[i];
    map<int, set<pair<int, int>>> xlst;
    xlst[-INF].emplace(0, 0);
    rep(i, n) {
        xlst[s[i]-x[i]].emplace(1, x[i]);
        xlst[t[i]-x[i]].emplace(-1, x[i]);
    }
    xlst[INF].emplace(0, 0);
    vector<int> res(q);
    auto itr = xlst.begin();
    map<int, int> xcnt;
    rep(i, q) {
        while (itr->first <= d[i]) {
            for (const auto pi : itr->second) if (pi.first != 0) {
                xcnt[pi.second] += pi.first;
                if (xcnt[pi.second] == 0) xcnt.erase(pi.second);
            }
            ++itr;
        }
        if (xcnt.empty()) res[i] = -1;
        else res[i] = xcnt.begin()->first;
    }
    rep(i, q) cout << res[i] << endl;
    return 0;
}
