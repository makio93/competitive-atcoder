#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC3(状態が重複しないようにDFSすることで高速化)

int n;
vector<string> s;

ll dfs(int d) {
    if (d == 0) return 1;
    queue<pair<int, int>> forbidden;
    ll res = 0;
    rep(i, n) rep(j, n) if (s[i][j] == '.') {
        vector<int> di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
        bool ok = false;
        rep(i2, 4) {
            int ni = i + di[i2], nj = j + dj[i2];
            if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
            if (s[ni][nj] != '@') continue;
            ok = true;
        }
        if (ok) {
            s[i][j] = '@';
            res += dfs(d-1);
            s[i][j] = '#';
            forbidden.emplace(i, j);
        }
    }
    while (!forbidden.empty()) {
        auto p = forbidden.front(); forbidden.pop();
        s[p.first][p.second] = '.';
    }
    return res;
}

int main() {
    int k;
    cin >> n >> k;
    s = vector<string>(n);
    rep(i, n) cin >> s[i];
    ll res = 0;
    rep(i, n) rep(j, n) if (s[i][j] == '.') {
        s[i][j] = '@';
        res += dfs(k-1);
        s[i][j] = '#';
    }
    cout << res << endl;
    return 0;
}
