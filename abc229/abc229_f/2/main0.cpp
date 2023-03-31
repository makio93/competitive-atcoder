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

template <class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const ll LINF = (ll)(1e18);

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector dp0(n+1, vector(2, LINF)), dp1(n+1, vector(2, LINF));
    dp0[0][0] = a[0];
    rep(i, n) {
        if (i+1 < n) {
            chmin(dp0[i+1][0], min(dp0[i][0]+b[i]+a[i+1], dp0[i][1]+a[i+1]));
            chmin(dp0[i+1][1], min(dp0[i][0], dp0[i][1]+b[i]));
        }
        else chmin(dp0[i+1][0], min(dp0[i][0]+b[i], dp0[i][1]));
    }
    dp1[0][1] = 0;
    rep(i, n) {
        if (i+1 < n) {
            chmin(dp1[i+1][0], min(dp1[i][0]+b[i]+a[i+1], dp1[i][1]+a[i+1]));
            chmin(dp1[i+1][1], min(dp1[i][0], dp1[i][1]+b[i]));
        }
        else chmin(dp1[i+1][1], min(dp1[i][0], dp1[i][1]+b[i]));
    }
    ll res = min(dp0[n][0], dp1[n][1]);
    cout << res << endl;
    return 0;
}
