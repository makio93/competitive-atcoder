#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説ACその2

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<bitset<100001>> dp(n+1, bitset<100001>(0));
    dp[0][0] = 1;
    rep(i, n) dp[i+1] = (dp[i]<<a[i]) | (dp[i]<<b[i]);
    if (!dp[n][s]) cout << "Impossible" << endl;
    else {
        int pos = s;
        string res;
        repr(i, n) {
            if (pos-a[i]>=0 && dp[i][pos-a[i]]) {
                pos -= a[i];
                res += 'A';
            }
            else {
                pos -= b[i];
                res += 'B';
            }
        }
        reverse(all(res));
        cout << res << endl;
    }
    return 0;
}
