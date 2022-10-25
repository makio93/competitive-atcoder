// 学習2回目,自力AC

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

const int INF = (int)(1e9);
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };

int main() {
    int h, w, ch, cw, dh, dw;
    cin >> h >> w >> ch >> cw >> dh >> dw;
    --ch; --cw; --dh; --dw;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<int>> dist(h, vector<int>(w, INF));
    deque<pair<int, int>> deq;
    deq.emplace_front(ch, cw);
    dist[ch][cw] = 0;
    while (!deq.empty()) {
        auto pi = deq.front(); deq.pop_front();
        int y = pi.first, x = pi.second, di = dist[y][x];
        rep(ii, 4) {
            int ny = y + dy[ii], nx = x + dx[ii];
            if (ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#' || dist[ny][nx]<=di) continue;
            deq.emplace_front(ny, nx);
            dist[ny][nx] = di;
        }
        for (int ii=-2; ii<=2; ++ii) for (int jj=-2; jj<=2; ++jj) {
            int ny = y + ii, nx = x + jj, ndi = di + 1;
            if (ny<0 || ny>=h || nx<0 || nx>=w || s[ny][nx]=='#' || dist[ny][nx]<=ndi) continue;
            deq.emplace_back(ny, nx);
            dist[ny][nx] = ndi;
        }
    }
    int res = dist[dh][dw];
    if (res == INF) res = -1;
    cout << res << endl;
    return 0;
}
