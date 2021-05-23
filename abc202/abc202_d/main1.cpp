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

// 解説を見てから作成、AC

vector<vector<ll>> dp;
string calc(int a, int b, ll k) {
    if (a == 0) return string(b, 'b');
    else if (b == 0) return string(a, 'a');
    else {
        if (dp[a-1][b] >= k) return string("a") + calc(a-1, b, k);
        else return string("b") + calc(a, b-1, k-dp[a-1][b]);
    }
}

int main() {
    int a, b;
    ll k;
    cin >> a >> b >> k;
    dp = vector<vector<ll>>(a+1, vector<ll>(b+1));
    dp[0][0] = 1;
    rep(i, a+1) rep(j, b+1) {
        if (i-1 >= 0) dp[i][j] += dp[i-1][j];
        if (j-1 >= 0) dp[i][j] += dp[i][j-1];
    }
    cout << calc(a, b, k) << endl;
    return 0;
}
