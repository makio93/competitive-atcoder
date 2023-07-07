// バチャ本番AC

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

const vi dy = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dx = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int main(){
    int n, m;
    cin >> n >> m;
    vs s(n);
    rep(i, n) cin >> s[i];
    vs ans(n, string(m, '0'));
    rep(i, n) rep(j, m) {
        int cnt = 0;
        rep(i2, 9) {
            int ny = i + dy[i2], nx = j + dx[i2];
            if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
            if (s[ny][nx] == '#') ++cnt;
        }
        ans[i][j] += cnt;
    }
    rep(i, n) cout << ans[i] << endl;
    return 0;
}
