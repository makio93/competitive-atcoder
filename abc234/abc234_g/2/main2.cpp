// 復習2,解説2

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

const ll mod = 998244353LL;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> dp(n+1);
    stack<int> mx_st, mn_st;
    stack<ll> mxs_st, mns_st;
    dp[0] = 1;
    ll mx_sum = 0, mn_sum = 0;
    rep(i, n) {
        {
            ll nxt_mxs = dp[i];
            while (!mx_st.empty() && mx_st.top()<=a[i]) {
                nxt_mxs = (nxt_mxs + mxs_st.top()) % mod;
                mx_sum = (mx_sum - mxs_st.top() * mx_st.top() % mod + mod) % mod;
                mx_st.pop(), mxs_st.pop();
            }
            mx_sum = (mx_sum + nxt_mxs * a[i] % mod) % mod;
            mx_st.emplace(a[i]), mxs_st.emplace(nxt_mxs);
        }
        {
            ll nxt_mns = dp[i];
            while (!mn_st.empty() && mn_st.top()>=a[i]) {
                nxt_mns = (nxt_mns + mns_st.top()) % mod;
                mn_sum = (mn_sum - mns_st.top() * mn_st.top() % mod + mod) % mod;
                mn_st.pop(), mns_st.pop();
            }
            mn_sum = (mn_sum + nxt_mns * a[i] % mod) % mod;
            mn_st.emplace(a[i]), mns_st.emplace(nxt_mns);
        }
        dp[i+1] = (mx_sum - mn_sum + mod) % mod;
    }
    cout << dp[n] << endl;
    return 0;
}
