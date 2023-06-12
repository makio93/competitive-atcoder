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

const int w_max = 1e5+1;

struct BIT {
    vi data;
    BIT(int n) : data(n+1, 0) {}
    int query(int i) {
        int m = 0;
        while (i > 0) {
            m = max(m, data[i]);
            i -= i & -i;
        }
        return m;
    }
    void update(int i, int a) {
        while (i <= int(data.size())) {
            data[i] = max(data[i], a);
            i += i & -i;
        }
    }
};

int main(){
    int n;
    cin >> n;
    vpii hw(n);
    rep(i, n) cin >> hw[i].second >> hw[i].first;
    rep(i, n) hw[i].second *= -1;
    VSORT(hw);
    rep(i, n) hw[i].second *= -1;
    vi dp(n);
    BIT b(w_max);
    rep(i, n) {
        dp[i] = b.query(hw[i].second-1) + 1;
        b.update(hw[i].second, dp[i]);
    }
    int ans = *max_element(all(dp));
    cout << ans << endl;
    return 0;
}
