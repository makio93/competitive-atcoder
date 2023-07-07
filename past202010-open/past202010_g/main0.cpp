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

int main(){
    int n, m;
    cin >> n >> m;
    vs s(n);
    rep(i, n) cin >> s[i];
    int ans = 0;
    rep(i, n) rep(j, m) {
        if (s[i][j] != '#') continue;
        vs t = s;
        queue<pii> q;
        q.emplace(i, j);
        t[i][j] = '*';
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int y = p.first, x = p.second;
            const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            rep(i2, 4) {
                int ny = y + dy[i2], nx = x + dx[i2];
                if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                if (t[ny][nx] != '.') continue;
                q.emplace(ny, nx);
                t[ny][nx] = '*';
            }
        }
        bool ok = true;
        rep(i2, n) rep(j2, m) if (t[i2][j2] == '.') ok = false;
        if (ok) ++ans;
    }
    cout << ans << endl;
    return 0;
}
