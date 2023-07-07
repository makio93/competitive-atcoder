// 自力WA(ヒント有)

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

vs s(18);
ll calc(int i, int j, int val) {
    if (s[i][j] != '?') return 0;
    s[i][j] = (char)(val+'0');
    ll res = 0;
    vector<vll> dp(4, vll(2, -1));
    const vi di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
    rep(i2, 1<<4) {
        vi t(4);
        rep(j2, 4) {
            if ((i2>>j2)&1) t[j2] = 1;
            else t[j2] = 0;
        }
        auto t2 = t;
        t2.pb(val);
        VSORT(t2);
        if (t2[2] != val) continue; 
        bool ok = true, rec = false;
        rep(j2, 4) {
            int ni = i + di[j2], nj = j + dj[j2];
            if (ni<0 || ni>=18 || nj<0 || nj>=6) {
                if (t[j2] != 0) ok = false;
            }
            else {
                if (s[ni][nj] != '?') {
                    if (s[ni][nj]-'0' != t[j2]) ok = false;
                }
                else rec = true;
            }
        }
        if (!ok) continue;
        ll sum = 1;
        if (rec) {
            rep(j2, 4) {
                int ni = i + di[j2], nj = j + dj[j2];
                if (s[ni][nj] != '?') continue;
                if (dp[j2][t[j2]] == -1) dp[j2][t[j2]] = calc(ni, nj, t[j2]);
                sum *= dp[j2][t[j2]];
            }
        }
        res += sum;
    }
    s[i][j] = '?';
    return res;
}

int main(){
    rep(i, 18) cin >> s[i];
    ll ans = 0;
    rep(i, 18) rep(j, 6) {
        if (s[i][j] != '?') continue;
        ans += calc(i, j, 0);
        ans += calc(i, j, 1);
    }
    cout << ans << endl;
    return 0;
}
