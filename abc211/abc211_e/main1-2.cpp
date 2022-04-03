// 解説AC1-2(解説寄りのやり方)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int n;
vector<string> s;
set<vector<string>> used;
ll dfs(int d) {
    if (used.find(s) != used.end()) return 0;
    used.insert(s);
    if (d == 0) return 1;
    queue<pair<int, int>> que;
    rep(i, n) rep(j, n) if (s[i][j] == '.') {
        vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
        bool ok = false;
        rep(i2, 4) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
            if (s[ni][nj] != '@') continue;
            ok = true;
        }
        if (ok) que.emplace(i, j);
    }
    ll res = 0;
    while (!que.empty()) {
        auto [i, j] = que.front(); que.pop();
        s[i][j] = '@';
        res += dfs(d-1);
        s[i][j] = '.';
    }
    return res;
}

int main() {
    int k;
    cin >> n >> k;
    s = vector<string>(n);
    rep(i, n) cin >> s[i];
    ll res = 0;
    used.insert(s);
    rep(i, n) rep(j, n) if (s[i][j] == '.') {
        s[i][j] = '@';
        res += dfs(k-1);
        s[i][j] = '.';
    }
    cout << res << endl;
    return 0;
}
