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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int white = 0;
    rep(i, h) rep(j, w) {
        if (s[i][j] == '.') ++white;
    }
    vector<vector<int>> d(h, vector<int>(w, INF));
    queue<pair<int, int>> q;
    auto ps = [&] (int i, int j, int dist) {
        if (i<0||i>=h||j<0||j>=w) return;
        if (s[i][j] != '.') return;
        q.push({i, j});
        d[i][j] = dist;
        s[i][j] = ' ';
    };
    const int di[] = { -1, 1, 0, 0 }, dj[] = { 0, 0, -1, 1 };
    ps(0, 0, 0);
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int i = p.first, j = p.second, dist = d[i][j];
        rep(i2, 4) {
            int ni = i + di[i2], nj = j + dj[i2];
            ps(ni, nj, dist + 1);
        }
    }
    int res = d[h-1][w-1];
    int ans = (res!=INF)?(white-res-1):-1;
    cout << ans << endl;
    return 0;
}
