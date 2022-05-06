// 学習1回目,自力AC

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
    vector<string> m(h);
    rep(i, h) cin >> m[i];
    int ans = 0;
    const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
    rep3(k, 1, n+1) {
        char f = (k==1)?'S':k-1+'0', t = k+'0';
        queue<pair<int, int>> q;
        vector<vector<int>> dist(h, vector<int>(w, INF));
        rep(i, h) rep(j, w) {
            if (m[i][j]==f) {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
        bool ok = false;
        while (!ok) {
            pair<int, int> p = q.front(); q.pop();
            int y = p.first, x = p.second;
            rep(i, 4) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0||ny>=h||nx<0||nx>=w) continue;
                if (m[ny][nx]=='X') continue;
                if (dist[ny][nx]!=INF) continue;
                if (m[ny][nx]==t) {
                    ans += dist[y][x] + 1;
                    ok = true;
                    break;
                }
                q.emplace(ny, nx);
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
