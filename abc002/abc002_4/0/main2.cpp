// 学習0回目,解説AC,解法2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

vector<vector<bool>> g(12, vector<bool>(12));
int n, ans = 0;
void dfs(vector<int> v, int k) {
    if (k == n) {
        rep(i, v.size()) for (int j=i+1; j<int(v.size()); ++j) {
            if (!g[v[i]][v[j]]) return;
        }
        ans = max(ans, int(v.size()));
        return;
    }
    dfs(v, k+1);
    v.push_back(k);
    dfs(v, k+1);
}

int main(){
    int m;
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x][y] = true;
        g[y][x] = true;
    }
    vector<int> v;
    dfs(v, 0);
    cout << ans << endl;
    return 0;
}
