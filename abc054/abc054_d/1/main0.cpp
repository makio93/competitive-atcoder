// 学習1回目,自力AC

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
    int mval = n * 10;
    vector<int> dp(mval*mval+1, INF);
    dp[0] = 0;
    rep(i, n) repr(j, mval*mval) {
        int add = a[i] * mval + b[i];
        if (j+add>mval*mval || dp[j]==INF) continue;
        chmin(dp[j+add], dp[j]+c[i]);
    }
    int res = INF;
    rep3(i, 1, mval*mval+1) {
        int ai = i / mval, bi = i % mval;
        if (ai>0 && bi>0 && ai*mb==bi*ma) res = min(res, dp[i]);
    }
    if (res == INF) res = -1;
    cout << res << endl;
    return 0;
}
