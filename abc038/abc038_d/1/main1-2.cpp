// 学習1回目,解説AC2

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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct BIT {
    int n;
    vi bit;
    BIT(int n) : n(n) { bit = vi(n+1); }
    int query(int i) {
        int m = 0;
        while (i > 0) {
            m = max(m, bit[i]);
            i -= i & -i;
        }
        return m;
    }
    void update(int i, int a) {
        while (i <= n) {
            bit[i] = max(bit[i], a);
            i += i & -i;
        }
    }
};

int main(){
    int n;
    cin >> n;
    vpii wh(n);
    rep(i, n) cin >> wh[i].second >> wh[i].first;
    VSORT(wh);
    vi dp(n+1);
    BIT b(1e5);
    int now = 0;
    rep(i, n) {
        if (wh[i].first!=wh[i-1].first) {
            while (now<i) {
                ++now;
                b.update(wh[now-1].second, dp[now]);
            }
        }
        dp[i+1] = b.query(wh[i].second-1) + 1;
    }
    int ans = 0;
    rep1(i, n) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
