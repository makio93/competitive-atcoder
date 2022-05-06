// 学習0回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

vector<vector<int>> g;
vector<int> ans;
void dfs(int v, int p=-1) {
    ans[v] += ans[p];
    for (int t : g[v]) {
        if (t == p) continue;
        dfs(t, v);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    g.resize(n);
    ans.resize(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, q) {
        int p, x;
        cin >> p >> x;
        --p;
        ans[p] += x;
    }
    dfs(0);
    rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    return 0;
}
