// 学習3回目,解説AC2

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

const double DINF = 1e18;
const int INF = (int)(1.1e9);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int mval = *max_element(all(a));
    double lval1 = 1.0, rval1 = (double)(mval+1);
    while (rval1-lval1 > (1e-3)*rval1) {
        double cval = sqrt(lval1*rval1);
        vector<vector<double>> dp(n+1, vector<double>(2, -DINF));
        dp[0][1] = 0.0;
        rep(i, n) {
            chmax(dp[i+1][0], dp[i][1]);
            chmax(dp[i+1][1], max(dp[i][0],dp[i][1])+(a[i]-cval));
        }
        if (max(dp[n][0], dp[n][1]) >= 0.0) lval1 = cval;
        else rval1 = cval;
    }
    int lval2 = 1, rval2 = mval + 1;
    while (rval2-lval2 > 1) {
        int cval = lval2 + (rval2-lval2) / 2;
        vector<vector<int>> dp(n+1, vector<int>(2, -INF));
        dp[0][1] = 0;
        rep(i, n) {
            chmax(dp[i+1][0], dp[i][1]);
            chmax(dp[i+1][1], max(dp[i][0],dp[i][1])+(a[i]>=cval?1:-1));
        }
        if (max(dp[n][0], dp[n][1]) > 0) lval2 = cval;
        else rval2 = cval;
    }
    cout << lval1 << endl;
    cout << lval2 << endl;
    return 0;
}
