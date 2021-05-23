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

// 解説を見てから作成、2つ目の解法、AC

int main() {
    int a, b;
    ll k;
    cin >> a >> b >> k;
    vector<vector<ll>> dp(a+1, vector<ll>(b+1));
    dp[0][0] = 1;
    rep(i, a+1) rep(j, b+1) {
        if (i-1 >= 0) dp[i][j] += dp[i-1][j];
        if (j-1 >= 0) dp[i][j] += dp[i][j-1];
    }
    while (a>0 && b>0) {
        if (dp[a-1][b] >= k) {
            cout << 'a';
            --a;
        }
        else {
            cout << 'b';
            k -= dp[a-1][b];
            --b;
        }
    }
    cout << string(a, 'a');
    cout << string(b, 'b');
    cout << endl;
    return 0;
}
