#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    dp[0][0] = true;
    rep(i, n) {
        rep(j, s+1) if (dp[i][j]) {
            if (j+a[i] <= s) dp[i+1][j+a[i]] = true;
            if (j+b[i] <= s) dp[i+1][j+b[i]] = true;
        }
    }
    if (!dp[n][s]) cout << "Impossible" << endl;
    else {
        string res;
        int val = s;
        repr(i, n) {
            if (val-a[i]>=0 && dp[i][val-a[i]]) {
                res += 'A';
                val -= a[i];
            }
            else {
                res += 'B';
                val -= b[i];
            }
        }
        reverse(all(res));
        cout << res << endl;
    }
    return 0;
}
