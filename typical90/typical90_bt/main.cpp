#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 自力AC

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> c(h);
    rep(i, h) cin >> c[i];
    int res = -1;
    rep(i0, h*w) if (c[i0/w][i0%w] == '.') {
        vector<vector<int>> dist(h*w, vector<int>((1<<(h*w)), -1));
        queue<pair<int, int>> que;
        que.emplace(i0, 0);
        dist[i0][0] = 0;
        while (!que.empty()) {
            auto p0 = que.front(); que.pop();
            int v = p0.first, p = p0.second, d = dist[v][p], nd = d + 1;
            if (p!=0 && v==i0) continue;
            const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            rep(i, 4) {
                int ny = v/w + dy[i], nx = v%w + dx[i], nv = ny * w + nx;
                if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if (c[ny][nx] == '#') continue;
                if (nd<3 && nv==i0) continue;
                if (((p>>nv)&1) == 1) continue;
                int np = p | (1<<nv);
                if (dist[nv][np] >= nd) continue;
                que.emplace(nv, np);
                dist[nv][np] = nd;
            }
        }
        rep(i, (1<<(h*w))) res = max(res, dist[i0][i]);
    }
    if (res <= 2) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}
