// 学習1回目,解説AC

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

int g[15][15];

int main(){
    int n;
    cin >> n;
    rep(i, n) rep(j, n) g[i][j] = -1;
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            g[i][--x] = y;
        }
    }
    int ans = 0;
    rep(i, 1<<n) {
        int d[15] = {};
        rep(j, n) {
            if (i>>j&1) d[j] = 1;
        }
        bool ok = true;
        rep(j, n) {
            if (d[j]) {
                rep(k, n) {
                    if (g[j][k]==-1) continue;
                    if (g[j][k]!=d[k]) ok = false;
                }
            }
        }
        if (ok) ans = max(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
    return 0;
}
