// 本番AC

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

int n;
vector<int> c;
vector<vector<int>> g;
vector<int> ans;
map<int, int> color;
void dfs(int vi=0, int pi=-1) {
    if (color.find(c[vi]) == color.end()) {
        ans.push_back(vi+1);
        color[c[vi]] = vi;
    }
    rep(i, (int)(g[vi].size())) {
        int to = g[vi][i];
        if (to == pi) continue;
        dfs(to, vi);
    }
    if (color[c[vi]] == vi) {
        color.erase(c[vi]);
    }
    return;
}

int main(){
    cin >> n;
    c = vector<int>(n);
    rep(i, n) cin >> c[i];
    g = vector<vector<int>>(n);
    rep(i, n-1) {
        int ai, bi;
        cin >> ai >> bi;
        --ai; --bi;
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    dfs();
    sort(all(ans));
    int m = (int)(ans.size());
    rep(i, m) cout << ans[i] << endl;
    return 0;
}
