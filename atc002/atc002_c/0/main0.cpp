// 自力,WA

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
    int n;
    cin >> n;
    vi w(n);
    rep(i, n) cin >> w[i];
    vi sum(n+1);
    rep(i, n) sum[i+1] = sum[i] + w[i];
    vector<vll> dp(n+1, vll(n+1, -1));
    function<ll (int, int)> calc = [&] (int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (r-l <= 1) return (dp[l][r] = sum[r]-sum[l]);
        auto itr1 = sum.begin(), itr2 = sum.begin();
        itr1 += (l+1); itr2 += (r+1);
        int c = upper_bound(itr1, itr2, (sum[l]+sum[r])/2) - sum.begin();
        ll res = INF;
        if (c-1>=l+1) res = min(res, calc(l,c-1)+calc(c-1,r));
        if (c<=r-1) res = min(res, calc(l,c)+calc(c,r));
        res += sum[r] - sum[l];
        return (dp[l][r] = res);
    };
    cout << (calc(0, n)-(sum[n]-sum[0])) << endl;
    return 0;
}
