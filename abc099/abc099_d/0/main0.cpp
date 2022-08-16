// 自力AC

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
    int n, c;
    cin >> n >> c;
    vector<vi> d(c, vi(c));
    rep(i, c) rep(j, c) cin >> d[i][j];
    vector<vi> ci(n, vi(n));
    rep(i, n) rep(j, n) {
        cin >> ci[i][j];
        ci[i][j]--;
    }
    vector<vi> cnt(3, vi(c));
    rep(i, n) rep(j, n) {
        cnt[((i+1)+(j+1))%3][ci[i][j]]++;
    }
    int ans = INF;
    rep(i, c) rep(j, c) rep(k, c) {
        if (!(i!=j&&j!=k&&k!=i)) continue;
        int sum = 0;
        rep(i2, c) sum += cnt[0][i2] * d[i2][i];
        rep(i2, c) sum += cnt[1][i2] * d[i2][j];
        rep(i2, c) sum += cnt[2][i2] * d[i2][k];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
