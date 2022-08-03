// 解説AC2

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
    vector<vector<vi>> ls(n+1, vector<vi>(n+1, vi(n+1)));
    rep1(h, n) rep1(i, n) {
        ls[h][0][i] = ls[h][0][i-1] + d[h-1][i-1];
        repr(j, i) ls[h][j][i] = ls[h][0][i] - ls[h][0][j];
    }
    vi mx(n*n+1);
    rep(i, n) for (int j=i+1; j<=n; ++j) rep(i2, n) {
        int sum = 0;
        for (int j2=i2+1; j2<=n; ++j2) {
            sum += ls[j2][i][j];
            int area = (j-i)*(j2-i2);
            mx[area] = max(mx[area], sum);
        }
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
