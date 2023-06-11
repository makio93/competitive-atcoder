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

const int INF = (int)(1e9);

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    unordered_map<int, unordered_set<int>> xtoy;
    rep(i, n) xtoy[x[i]].insert(y[i]);
    ll res = 0;
    for (auto itr=xtoy.begin(); itr!=xtoy.end(); ++itr) for (auto ritr=next(itr); ritr!=xtoy.end(); ++ritr) {
        int cnt = 0;
        for (const int& yi : itr->second) if (ritr->second.find(yi) != ritr->second.end()) ++cnt;
        res += cnt * (ll)(cnt - 1) / 2;
    }
    cout << res << endl;
    return 0;
}
