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

int n, k;
vector<vector<bool>> board, visited, now;
ll dfs(int y, int x, int d) {
    now[y][x] = true;
    if (d == 0) return 1;
    const vector<int> dy = { 0, 1, 0 }, dx = { 1, 0, -1 };
    ll res = 0;
    rep(i2, 3) {
        int ny = y + dy[i2], nx = x + dx[i2];
        if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
        if (!board[ny][nx] || visited[ny][nx] || now[ny][nx]) continue;
        res += dfs(ny, nx, d-1);
    }
    now[y][x] = false;
    return res;
}

int main() {
	cin >> n >> k;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
    board = vector<vector<bool>>(n, vector<bool>(n));
    rep(i, n) rep(j, n) if (s[i][j] == '.') board[i][j] = true;
    visited = vector<vector<bool>>(n, vector<bool>(n));
    now = vector<vector<bool>>(n, vector<bool>(n));
    ll res = 0;
    rep(i, n) rep(j, n) if (board[i][j]) {
        res += dfs(i, j, k-1);
        visited[i][j] = true;
    }
    cout << res << endl;
    return 0;
}
