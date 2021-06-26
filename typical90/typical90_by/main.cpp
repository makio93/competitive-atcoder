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

// 自力AC

const int INF = (int)(1e9);

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> ax(n), ay(n), bx(n), by(n);
    rep(i, n) cin >> ax[i] >> ay[i];
    rep(i, n) cin >> bx[i] >> by[i];
    map<pair<int, int>, int> bid;
    rep(i, n) bid[{ bx[i], by[i] }] = i;
    mf_graph<int> g(2*n+2);
    vector<map<int, int>> adata(n);
    rep(i, n) {
        const vector<int> dx = { 1, 1, 0, -1, -1, -1, 0, 1 }, dy = { 0, 1, 1, 1, 0, -1, -1, -1 };
        rep(j, 8) {
            ll nx = ax[i] + (ll)dx[j] * t, ny = ay[i] + (ll)dy[j] * t;
            if (nx<0 || nx>INF || ny<0 || ny>INF) continue;
            if (bid.find({ nx, ny }) == bid.end()) continue;
            int bi = bid[{ nx, ny }];
            g.add_edge(i, n+bi, 1);
            adata[i][n+bi] = j;
        }
    }
    rep(i, n) g.add_edge(2*n, i, 1);
    rep3(i, n, 2*n) g.add_edge(i, 2*n+1, 1);
    int res = g.flow(2*n, 2*n+1, n);
    if (res < n) cout << "No" << endl;
    else {
        vector<int> d(n);
        auto ev = g.edges();
        for (auto ei : ev) if (ei.from<n && ei.flow==1) d[ei.from] = adata[ei.from][ei.to] + 1;
        cout << "Yes" << endl;
        rep(i, n) printf("%d%c", d[i], (i<n-1?' ':'\n'));
    }
    return 0;
}
