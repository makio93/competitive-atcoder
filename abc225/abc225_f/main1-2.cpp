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

// 解説AC1-2

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end(), [](string a, string b) { return (a+b<b+a || (a+b==b+a&&a<b)); });
    vector<vector<string>> dp(n+1, vector<string>(n+1));
    repr(i, n) rep3(j, 1, min(k,n-i)+1) {
        dp[i][j] = s[i] + dp[i+1][j-1];
        if (min(k,n-(i+1)) >= j) dp[i][j] = min(dp[i][j], dp[i+1][j]);
    }
    cout << dp[0][k] << endl;
    return 0;
}
