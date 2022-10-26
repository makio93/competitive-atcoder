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

int a[3][3], b[10];
bool d[3][3];

int main(){
    rep(i, 3) rep(j, 3) cin >> a[i][j];
    int n;
    cin >> n;
    rep(k, n) cin >> b[k];
    rep(i, 3) rep(j, 3) {
        d[i][j] = false;
        rep(k, n) if (a[i][j] == b[k]) d[i][j] = true;
    }
    string ans = "No";
    rep(i, 3) {
        if (d[i][0] and d[i][1] and d[i][2]) ans = "Yes";
    }
    rep(j, 3) {
        if (d[0][j] and d[1][j] and d[2][j]) ans = "Yes";
    }
    {
        if (d[0][0] and d[1][1] and d[2][2]) ans = "Yes";
    }
    {
        if (d[0][2] and d[1][1] and d[2][0]) ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}
