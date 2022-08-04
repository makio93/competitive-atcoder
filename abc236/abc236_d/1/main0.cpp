// 復習1回目,自力AC

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
    vector<vector<int>> a(2*n, vector<int>(2*n));
    rep(i, 2*n-1) rep3(j, i+1, 2*n) {
        int ai;
        cin >> ai;
        a[i][j] = a[j][i] = ai;
    }
    int res = 0;
    vector<bool> choosed(2*n);
    auto dfs = [&](auto dfs, int di=0, int val=0) -> void {
        if (di == n) {
            res = max(res, val);
            return;
        }
        int li = 0;
        while (choosed[li]) ++li;
        choosed[li] = true;
        rep3(ri, li+1, 2*n) if (!choosed[ri]) {
            choosed[ri] = true;
            dfs(dfs, di+1, val^a[li][ri]);
            choosed[ri] = false;
        }
        choosed[li] = false;
    };
    dfs(dfs);
    cout << res << endl;
    return 0;
}
