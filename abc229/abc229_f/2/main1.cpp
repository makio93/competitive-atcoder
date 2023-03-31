// 学習2回目,解説AC

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

const ll LINF = (ll)(1e18);

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector dp(2, vector(n, vector(2, LINF)));
    dp[0][0][0] = a[0];
    dp[1][0][1] = 0;
    rep3(i, 1, n) rep(j, 2) rep(k, 2) rep(j2, 2) chmin(dp[k][i][j], dp[k][i-1][j2]+(j==0?a[i]:0)+(j==j2?b[i-1]:0));
    ll res = LINF;
    rep(i, 2) rep(j, 2) chmin(res, dp[j][n-1][i]+(i==j?b[n-1]:0));
    cout << res << endl;
    return 0;
}
