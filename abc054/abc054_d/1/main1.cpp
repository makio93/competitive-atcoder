// 学習1回目,解説AC

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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int INF = (int)(1e9);

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];
    int mv = n * 10;
    vector<vector<int>> dp(mv+1, vector<int>(mv+1, INF));
    dp[0][0] = 0;
    rep(i, n) repr(j1, mv) repr(j2, mv) {
        if (dp[j1][j2]==INF || j1+a[i]>mv || j2+b[i]>mv) continue;
        chmin(dp[j1+a[i]][j2+b[i]], dp[j1][j2]+c[i]);
    }
    int res = INF;
    rep3(i, 1, mv+1) rep3(j, 1, mv+1) if (i*mb == j*ma) res = min(res, dp[i][j]);
    if (res == INF) res = -1;
    cout << res << endl;
    return 0;
}
