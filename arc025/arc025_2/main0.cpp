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
    int h, w;
    cin >> h >> w;
    vector<vi> c(h, vi(w));
    rep(i, h) rep(j, w) cin >> c[i][j];
    vector<vi> sumb(h+1, vi(w+1)), sumw(h+1, vi(w+1));
    rep(i, h) rep(j, w) {
        if ((i+j)%2==0) {
            sumb[i+1][j+1] = sumb[i+1][j] + sumb[i][j+1] - sumb[i][j] + c[i][j];
            sumw[i+1][j+1] = sumw[i+1][j] + sumw[i][j+1] - sumw[i][j];
        }
        else {
            sumw[i+1][j+1] = sumw[i+1][j] + sumw[i][j+1] - sumw[i][j] + c[i][j];
            sumb[i+1][j+1] = sumb[i+1][j] + sumb[i][j+1] - sumb[i][j];
        }
    }
    int ans = 0;
    rep(i, h) for (int i2=i+1; i2<=h; ++i2) rep(j, w) for (int j2=j+1; j2<=w; ++j2) {
        int numb = sumb[i2][j2] - sumb[i2][j] - sumb[i][j2] + sumb[i][j];
        int numw = sumw[i2][j2] - sumw[i2][j] - sumw[i][j2] + sumw[i][j];
        if (numb == numw) ans = max(ans, (i2-i)*(j2-j));
    }
    cout << ans << endl;
    return 0;
}
