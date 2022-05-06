// 学習0回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans = 0;
    rep(i0, n) {
        char b = '0' + i0, e = '0' + (i0 + 1);
        if (b == '0') b = 'S';
        vector<string> s2 = s;
        queue<pair<int, int>> q;
        vector<vector<int>> d(h, vector<int>(w, INF));
        auto ps = [&] (int i, int j, int b) {
            if (i<0||i>=h||j<0||j>=w) return;
            if (s2[i][j]=='X'||s2[i][j]==' ') return;
            q.push({i, j});
            s2[i][j] = ' ';
            d[i][j] = b;
        };
        int ib = 0, jb = 0, ie = 0, je = 0;
        rep(i, h) rep(j, w) {
            if (s2[i][j] == b) {
                ib = i; jb = j;
            }
            if (s2[i][j] == e) {
                ie = i; je = j;
            }
        }
        const int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        ps(ib, jb, 0);
        while (!q.empty()) {
            pair<int, int> p = q.front(); q.pop();
            int y = p.first, x = p.second;
            int b = d[y][x] + 1;
            rep(i, 4) {
                int nx = x + dx[i], ny = y + dy[i];
                ps(ny, nx, b);
            }
        }
        ans += d[ie][je];
    }
    cout << ans << endl;
    return 0;
}
