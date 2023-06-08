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

const int INF = (int)(2e9);

int main() {
    int n;
    cin >> n;
    vector<int> x(n), c(n);
    rep(i, n) {
        cin >> x[i];
        x[i]--;
    }
    rep(i, n) cin >> c[i];
    vector<vector<pair<int, int>>> g(n);
    rep(i, n) g[i].emplace_back(x[i], c[i]);
    vector<bool> visited(n), finished(n);
    function<pair<int,int>(int)> dfs = [&](int vi) {
        visited[vi] = true;
        int rci = INF, rvi = -1;
        if (!finished[x[vi]]) {
            if (visited[x[vi]]) {
                rci = c[vi];
                rvi = x[vi];
            }
            else {
                auto rpi = dfs(x[vi]);
                rci = min(rci, rpi.first);
                if (rpi.second != -1) rci = min(rci, c[vi]);
                rvi = (rpi.second != -1 && rpi.second == vi) ? -1 : rpi.second;
            }
        }
        else rci = 0;
        finished[vi] = true;
        return make_pair(rci, rvi);
    };
    ll res = 0;
    rep(i, n) if (!finished[i]) res += dfs(i).first;
    cout << res << endl;
    return 0;
}
