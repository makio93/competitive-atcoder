// 学習1回目,自力WA

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

const int INF = (int)(2e9);
using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<mint> dp(n+1);
    dp[0] = 1;
    stack<pair<int, mint>> st1, st2;
    rep(i, n) {
        mint pcnt = (i-1 >= 0) ? mint(2).pow(i-1) : 1;
        mint stcnt1 = pcnt, stcnt2 = pcnt, 
            nval1 = dp[i] * a[i] * pcnt, nval2 = dp[i] * a[i] * pcnt;
        while (!st1.empty() && (i+1>=n || a[st1.top().first]<=a[i])) {
            stcnt1 += st1.top().second;
            if (i+1 >= n) nval1 += dp[st1.top().first] * max(a[i], a[st1.top().first]) * st1.top().second;
            else nval1 += dp[st1.top().first] * a[i] * st1.top().second;
            st1.pop();
        }
        while (!st2.empty() && (i+1>=n || a[st2.top().first]>=a[i])) {
            stcnt2 += st2.top().second;
            if (i+1 >= n) nval2 += dp[st2.top().first] * min(a[i], a[st2.top().first]) * st2.top().second;
            else nval2 += dp[st2.top().first] * a[i] * st2.top().second;
            st2.pop();
        }
        if (st1.empty()) {
            stcnt1 += 1;
            nval1 += a[i];
        }
        if (st2.empty()) {
            stcnt2 += 1;
            nval2 += a[i];
        }
        st1.emplace(i, stcnt1);
        st2.emplace(i, stcnt2);
        dp[i+1] += nval1 - nval2;
    }
    cout << dp[n].val() << endl;
    return 0;
}
