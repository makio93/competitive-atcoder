#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const ll INF = (ll)(1e16);

int main() {
    int h, w, c;
    cin >> h >> w >> c;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<vector<ll>> ldp(h+1, vector<ll>(w+1, INF)), lx(h+1, vector<ll>(w+1, INF));
    vector<vector<ll>> rdp(h+1, vector<ll>(w+1, INF)), rx(h+1, vector<ll>(w+1, INF));
    rep(i, h) rep(j, w) {
        ldp[i+1][j+1] = min({(ll)a[i][j], min(INF, ldp[i][j+1]+c), min(INF, ldp[i+1][j]+c)});
        lx[i+1][j+1] = min(min(INF, ldp[i][j+1]+c+a[i][j]), min(INF, ldp[i+1][j]+c+a[i][j]));
    }
    rep(i, h) repr(j, w) {
        rdp[i+1][j] = min({(ll)a[i][j], min(INF, rdp[i][j]+c), min(INF, rdp[i+1][j+1]+c)});
        rx[i+1][j] = min(min(INF, rdp[i][j]+c+a[i][j]), min(INF, rdp[i+1][j+1]+c+a[i][j]));
    }
    ll res = INF;
    rep(i, h) rep(j, w) res = min({res, lx[i+1][j+1], rx[i+1][j]});
    cout << res << endl;
    return 0;
}
