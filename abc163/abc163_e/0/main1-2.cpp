// 解説AC2

#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

inline void chmax(ll& a, ll b) { a = max(a, b); }

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vpii p;
    rep(i, n) p.emplace_back(a[i], i);
    RSORT(p);
    vector<vll> dp(n+1, vll(n+1, -INF));
    dp[0][0] = 0;
    rep(i, n) {
        int ai = p[i].first, bi = p[i].second;
        rep(l, i+1) {
            int r = i - l;
            chmax(dp[i+1][l+1], dp[i][l]+ll(ai)*(bi-l));
            chmax(dp[i+1][l], dp[i][l]+ll(ai)*(n-r-bi-1));
        }
    }
    ll ans = 0;
    rep(i, n+1) chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}
