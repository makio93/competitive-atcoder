// 学習1回目,解説AC1

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
const ll mod = 998244353LL;

int main() {
    int n;
    cin >> n;
    vector<ll> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> dp(n+1);
    dp[0] = 1;
    rep(i, n) {
        int li = i, ri = i+1;
        while (li-1>=0 && p[li-1]<=p[i]) --li;
        while (ri<n && p[ri]<=p[i]) ++ri;
        rep3(j, li, ri) {
            dp[j+1] += dp[j];
            dp[j+1] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
