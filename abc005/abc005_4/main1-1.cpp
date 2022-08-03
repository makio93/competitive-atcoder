// 解説AC1

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
    int n, q;
    cin >> n;
    vector<vi> d(n, vi(n));
    rep(i, n) rep(j, n) cin >> d[i][j];
    vector<vi> sum(n+1, vi(n+1));
    rep(i, n) rep(j, n) {
        sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + d[i][j];
    }
    vi mx(n*n+1);
    rep(i, n) rep(j, n) for (int i2=i+1; i2<=n; ++i2) for (int j2=j+1; j2<=n; ++j2) {
        int val = sum[i2][j2] - sum[i][j2] - sum[i2][j] + sum[i][j];
        int num = (i2-i)*(j2-j);
        mx[num] = max(mx[num], val);
    }
    rep(i, n*n) mx[i+1] = max(mx[i+1], mx[i]);
    cin >> q;
    rep(i, q) {
        int p;
        cin >> p;
        cout << mx[p] << endl;
    }
    return 0;
}
