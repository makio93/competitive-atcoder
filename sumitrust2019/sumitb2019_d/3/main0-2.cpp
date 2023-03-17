// 学習3回目,自力AC2

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

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<bool>> dp(4);
    int si = 1;
    rep(i, 4) {
        dp[i].resize(si, false);
        si *= 10;
    }
    dp[0][0] = 1;
    rep(i, n) for (int j=100,tj=2; tj>=0; j/=10,--tj) rep(i2, j) dp[tj+1][i2*10+s[i]-'0'] = dp[tj+1][i2*10+s[i]-'0'] || dp[tj][i2];
    cout << count(all(dp[3]), true) << endl;
    return 0;
}
