// 解説AC

#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    ll n, wi;
    cin >> n >> wi;
    vll v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];
    ll vmx = 0;
    rep(i, n) vmx = max(vmx, v[i]);
    ll ans = 0;
    if (wi <= 200000) {
        vector<vll> dp(n+1, vll(wi+1));
        rep(i, n) rep(j, wi+1) {
            if (j-w[i]<0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
        }
        ans = dp[n][wi];
    }
    else if (vmx <= 1000) {
        int vali = vmx*n;
        vector<vll> dp(n+1, vll(vali+1, INF));
        dp[0][0] = 0;
        rep(i, n) rep(j, vali+1) {
            if (j-v[i]<0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
        }
        rep(i, vali+1) if (dp[n][i] <= wi) ans = i;
    }
    else {
        int ln = n/2, rn = n-ln;
        set<pll> st;
        rep(i, 1<<ln) {
            ll sum = 0, vsum = 0;
            rep(j, ln) if (i&(1<<j)) {
                sum += w[j];
                vsum += v[j];
            }
            st.insert({ sum, vsum });
        }
        auto itr = st.begin();
        ll tmp = -1;
        while (itr!=st.end()) {
            if (itr->second<=tmp) itr = st.erase(itr);
            else {
                tmp = itr->second;
                ++itr;
            }
        }
        rep(i, 1<<rn) {
            ll sum = 0, vsum = 0;
            rep(j, rn) if (i&(1<<j)) {
                sum += w[ln+j];
                vsum += v[ln+j];
            }
            auto itr = st.upper_bound({wi-sum, 0});
            if (itr==st.begin()) continue;
            --itr;
            ans = max(ans, vsum+(itr->second));
        }
    }
    cout << ans << endl;
    return 0;
}
