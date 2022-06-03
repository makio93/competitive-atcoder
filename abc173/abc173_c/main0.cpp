// 本番AC

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

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    vs c(h);
    rep(i, h) cin >> c[i];
    int ans = 0;
    rep(i, 1<<h) rep(j, 1<<w) {
        if (i==0 && j==0) continue;
        if (i==(1<<h)-1 || j==(1<<w)-1) continue;
        int cnt = 0;
        rep(i2, h) rep(j2, w) {
            bool ok = false;
            if (i&(1<<i2) || j&(1<<j2)) ok = true;
            if (ok) continue;
            if (c[i2][j2] == '#') ++cnt;
        }
        if (cnt == k) ++ans;
    }
    int cnt = 0;
    rep(i, h) rep(j, w) if (c[i][j] == '#') ++cnt;
    if (cnt == k) ++ans;
    cout << ans << endl;
    return 0;
}
