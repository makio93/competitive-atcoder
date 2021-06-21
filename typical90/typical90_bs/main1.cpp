#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        ++deg[bi];
    }
    vector<vector<int>> res;
    vector<int> perm(n, -1);
    set<int> s;
    function<bool(int)> dfs = [&](int dep) {
        if (dep == 0) {
            rep(i1, n) if (deg[i1] == 0) s.insert(i1);
        }
        if (dep == n) {
            if ((int)(res.size()) < k) res.push_back(perm);
            return true;
        }
        if (s.empty()) return false;
        for (auto itr=s.begin(); itr!=s.end(); ++itr) {
            if ((int)(res.size()) >= k) return true;
            int v = (*itr);
            perm[dep] = v;
            s.erase(itr);
            for (int t : g[v]) {
                deg[t]--;
                if (deg[t] == 0) s.insert(t);
            }
            if (!dfs(dep+1)) return false;
            for (int t : g[v]) {
                if (deg[t] == 0) s.erase(t);
                deg[t]++;
            }
            itr = s.insert(v).first;
            perm[dep] = -1;
        }
        return true;
    };
    dfs(0);
    if ((int)(res.size()) < k) cout << -1 << endl;
    else {
        rep(i, k) rep(j, n) printf("%d%c", res[i][j]+1, (j<n-1?' ':'\n'));
    }
    return 0;
}
